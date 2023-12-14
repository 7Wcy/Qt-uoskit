#include "uoskitgui.h"
#include "ui_uoskitgui.h"
void UoskitGui::onCloneProject(){

    QString selectedDirectory = QFileDialog::getExistingDirectory(this, "Select Directory", QDir::homePath());

    if (!selectedDirectory.isEmpty()) {
        ui->path_line->setText(selectedDirectory);
        // Set the working directory for QProcess
        QProcessEnvironment env = QProcessEnvironment::systemEnvironment();
        env.insert("PWD", selectedDirectory);
        // Run clone.sh script using QProcess with specified working directory
        QProcess::startDetached("/usr/bin/clone.sh", QStringList() << selectedDirectory, selectedDirectory, nullptr);
    }

}
