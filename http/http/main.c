#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <unistd.h>
#include "http.h"


int main(int argc, char *argv[]) {

  const char *url="www.baidu.com";
  const char *post_str="";
  int port=80;

  http_post(url,post_str);
  http_get(url);

  return 0;
}

