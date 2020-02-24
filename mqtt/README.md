<a href="https://blog.csdn.net/jsjwr/article/details/78800202" target="_blank">Ubuntu 16.04安装测试MQTT Mosquitto</a><br>
<a href="https://blog.csdn.net/caijiwyj/article/details/86671211" target="_blank">mosquitto库Linux c编程</a><br>
<a href="https://www.cnblogs.com/xcsn/p/11360413.html" target="_blank"></a>mosquitto 常用命令<br>
安装依赖
```
apt-get install -y openssl libssl-dev libssl-dev libc-ares-dev uuid-dev
wget -c https://mosquitto.org/files/source/mosquitto-1.6.8.tar.gz
tar xvf mosquitto-1.6.8.tar.gz;cd mosquitto-1.6.8
```
安装
```
make;make install
```
创建链接
```
ln -s /usr/local/lib/libmosquitto.so.1 /usr/lib/libmosquitto.so.1
```
更新链接
```
ldconfig
```
编译
```
gcc clientsubscribe.c -o clientsubscribe -lcrypto -lssl -lmosquitto
gcc clientpublish.c -o clientpublish -lcrypto -lssl -lmosquitto
```
