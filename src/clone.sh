#!/bin/bash

# 如果用户取消输入工号，则退出
if [ $? -ne 0 ]; then
    exit 0
fi

# 错误退出函数
error_exit() {
    zenity --error --width=200 --height=100 --text="错误：$1"
    exit 1
}

# 定义项目数组
projects=("deepin-kwin" "kwayland" "dde-kwin" "base/xorg-server" "dde-session-shell")

# 显示项目选项
selection=$(zenity --list --title="克隆" --width=200 --height=300 --column="项目" "${projects[@]}")

# 如果用户取消选择，则退出
if [ $? -ne 0 ]; then
    exit 0
fi

# 检查项目目录是否已经存在
if [ -d "$selection" ]; then
    error_exit "项目 '$selection' 在当前目录已存在，请重新选择。"
fi

# 提示用户输入工号
employee_id=$(zenity --entry --width=200 --height=100 --title="输入工号" --text="请输入您的工号:")

# 构建SSH格式的项目URL
git_url="$employee_id@gerrit.uniontech.com:29418"
project_url="$git_url/$selection"

clone_progress_bar() {
    (
        echo "0" ;
        echo "30" ;
        echo "# 正在克隆项目: $selection" ;
        git clone "ssh://$project_url" || { error_exit "clone失败，请检查网络或者权限是否有问题，请修正后，重新运行."; exit 1; }
        echo "50" ;
        echo "# 正在设置 Git 钩子" ;
        # 设置 Git 钩子
        scp_output=$(scp -p -P 29418 "$git_url:hooks/commit-msg" ".git/hooks/" 2>&1)
        echo "80" ;
        echo "scp输出：$scp_output" ; sleep 1
        if [ $? -ne 0 ]; then
            error_exit "复制Git钩子失败！"
            exit 1
        fi
    ) | zenity --progress --title="克隆项目" --width=400 --percentage=0 --auto-close
}

clone_progress_bar

if [ "$selection" == "deepin-kwin" ]; then
    selection="kwin"
fi

if [ "$selection" == "base/xorg-server " ]; then
    selection="xorg-server"
fi

# 获取 rely_name
rely_name=$selection

depend_dependencies_progress() {
    (
        echo "30" ;
        echo "# 尝试安装 $rely_name 依赖..." ;        
        sudo apt-get build-dep -y $rely_name; then
        if [ $? -ne 0 ]; then
             error_exit "安装依赖失败，请修正后，重新运行。"
        fi
 
    ) | zenity --progress --title="安装依赖" --width=400 --percentage=0 --auto-close
}


depend_dependencies_progress
