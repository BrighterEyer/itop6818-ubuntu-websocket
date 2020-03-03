
<a href="https://www.cnblogs.com/y-c-y/p/11686916.html" target="_blank">基于mosquitto的MQTT客户端实现C语言</a>
```
apt-get install -y g++ libssl-dev libc-ares-dev uuid-dev
wget -c  --no-check-certificate https://mosquitto.org/files/source/mosquitto-1.5.5.tar.gz
#解压
tar zxvf mosquitto-1.5.5.tar.gz;cd mosquitto-1.5.5
make;make install
```
解决编译问题
```
#创建链接
ln -s /usr/local/lib/libmosquitto.so.1 /usr/lib/libmosquitto.so.1
#更新链接
ldconfig
```

<a href="https://www.jianshu.com/p/9e3cb7042a2e" target="_blank">Mosquitto搭建及配置</a>
