1、需求和环境
硬件：一台装有Ubuntu系统的pc或者虚拟机（测试为Ubuntu11.10）
软件：openssh-server 、openssh-client 、git-core
2、安装配置git服务器
      a、安装ssh，因为git是基于ssh协议的，所以必须先装ssh：

    sudo apt-get install openssh-server openssh-client

           安装好ssh后，启动ssh服务：

    sudo /etc/init.d/ssh restart    

      b、安装git服务器：

    sudo apt-get install git-core

3、申请github帐号
      如果只是单纯的想要将github上感兴趣的代码拷贝到本地，或者使用git工具管理本地代码，那执行到第二步就已经完成了git在ubuntu下的配置，可以使用git来管理代码了。
      但是，如果想把代码进一步提交到github，让其管理，那就需要在github上注册一个新帐号，具体注册步骤省略。
4、配置ssh公钥
     a、首先在本地生成ssh公钥

    ssh-keygen -C 'your emaildress' -t rsa

       如：ssh-keygen -C 'dongyuchi@gmail.com' -t rsa
      会在用户目录～/.ssh/下建立相应的密钥文件
      可以使用ssh -v git@github.com命令来测试链接是否畅通

    ssh -v git@github.com

     b、上传公钥至github
       在账户的profile里，选择SSH KEYS 选项，然后Add SSH Key，将~/.ssh/id_rsa.pub中的内容复制进去，上传。
      上上传成功后，会收到确认邮件。 可以使用ssh -v git@github.com命令来测试链接是否畅通。
5、管理项目
     a、建立仓库
     创建一个新目录，用来作为仓库目录。进入目录，运行git init命令，进行仓库初始化，完成后，会发现目录下多了一个.git隐藏文件。

    git init

     b、git配置

    git config --global user.name "Your Real Name"
    git config --global user.email you@email.address

     c、添加文件

    git add ./

      这是添加目录下所有文件，如果只是添加某个文件，就将文件名字列出，如果添加目录，则可以用*代替。
    d、commit项目

    git commit -m 'my first version

     -m后面是对该项目的描述。
    e、上传项目

    git remote add origin git@github.com:你的github用户名/你的github项目名.git
    git push origin master

   在该步骤执行push时，有可能系统要求你先pull一下，那就先pull一下，再push。
