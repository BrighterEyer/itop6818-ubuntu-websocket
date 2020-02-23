
<a href="https://blog.csdn.net/Dancer__Sky/article/details/77855249" target="_blank">基于MQTT协议的Mosquitto的使用及libmosquitto客户端编程</a>
```
apt-get install -y g++ libssl-dev libc-ares-dev uuid-dev
wget -c https://mosquitto.org/files/source/mosquitto-1.5.5.tar.gz
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
启动mosquitto服务器
```
mosquitto -v

mosquitto -c /etc/mosquitto/mosquitto.conf -d
```
订阅消息（如topic）
```
mosquitto_sub -v -t topic
```
发布消息
```
mosquitto_pub -t topic -m good
```
编译
```
gcc -o mosquitto_client_sub mosquitto_client_sub.c -lmosquitto
```
