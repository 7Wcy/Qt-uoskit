#include <QApplication>
#include <QMessageBox>
#include <QProgressDialog>
#include <QLineEdit>
#include <QInputDialog>
#include <QProcess>
#include <QDir>
#include <QFileDialog>
#include "uoskitgui.h"
#include "ui_uoskitgui.h"

void UoskitGui::onCloneProject() {

    bool ok;
    QString employee_id = QInputDialog::getText(nullptr, "输入工号", "请输入您的工号:", QLineEdit::Normal, "", &ok);
    if (!ok) {
        return;
    }else if (employee_id.isEmpty()) {
        // 用户没有输入工号
        QMessageBox::warning(nullptr, "警告", "工号不能为空，请重新输入。");
        return;
    }

    // 获取目标文件夹路径
    QString selectedDirectory = QFileDialog::getExistingDirectory(this, "选择文件夹", QDir::homePath());
    if (selectedDirectory.isEmpty()) {
        return;
    }

    ui->path_line->setText(selectedDirectory);

    //设置QProcess的工作目录
    QProcessEnvironment env = QProcessEnvironment::systemEnvironment();
    env.insert("PWD", selectedDirectory);

    // 定义项目列表
    QStringList projects = {"deepin-kwin", "kwayland", "dde-kwin", "base/xorg-server", "dde-session-shell"};
    QString selection = QInputDialog::getItem(nullptr, "克隆", "选择项目", projects, 0, false, &ok);
    if (!ok) {
        return;
    }

    // 检查项目目录是否已经存在
    if (QDir(selectedDirectory + "/" + selection).exists()) {
        QMessageBox::critical(nullptr, "错误", QString("项目 '%1' 在当前目录已存在，请重新选择。").arg(selection));
        return;
    }

    // 构建SSH格式的项目URL，并追加目录路径
    QString git_url = QString("%1@gerrit.uniontech.com:29418").arg(employee_id);
    QString project_url = QString("%1/%2").arg(git_url, selection);


    QProcess gitProcess;
    gitProcess.setWorkingDirectory(selectedDirectory); // 设置工作目录为选定的目录

    QMessageBox::information(nullptr, "提示", "正在克隆中，请稍后...");

    //进行克隆
    gitProcess.start(QString("git clone ssh://%1").arg(project_url));
    if (!gitProcess.waitForFinished(-1)) {
        QMessageBox::critical(nullptr, "失败", "Clone失败，请检查网络或ssh权限并重新运行。");
        return;
    }

    if (gitProcess.exitCode() == 0) {
        QMessageBox::information(nullptr, "成功", "项目克隆成功！");
    } else {
        QMessageBox::critical(nullptr, "错误", "Clone失败，请检查网络或ssh权限并重新运行。");
    }
}


