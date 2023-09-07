#include <arpa/inet.h>
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <netinet/in.h>
#include <string>
#include <sys/socket.h>
#include <thread>
#include <unistd.h>

bool scanPort(const std::string &targetIP, int port, int timeout) {
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock == -1) {
    perror("socket");
    return false;
  }

  struct sockaddr_in server;
  server.sin_family = AF_INET;
  server.sin_port = htons(port);
  server.sin_addr.s_addr = inet_addr(targetIP.c_str());

  struct timeval tv;
  tv.tv_sec = timeout;
  tv.tv_usec = 0;

  if (setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv)) < 0) {
    perror("setsockopt");
    close(sock);
    return false;
  }

  if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == 0) {
    close(sock);
    return true;
  } else {
    close(sock);
    return false;
  }
}

void startPortScan(const std::string &targetIP, int timeout) {
  for (int port = 1; port <= 65535; ++port) {
    if (scanPort(targetIP, port, timeout)) {
      std::cout << "[SUCCESS] Port " << port << " is open" << std::endl;
    }
  }
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    std::cerr << "usage: " << argv[0] << " <targetIP> <timeout>" << std::endl;
    return 1;
  }

  std::string targetIP = argv[1];
  int timeout = std::stoi(argv[2]);

  std::cout << "starting port scan on " << targetIP << " with a timeout of "
            << timeout << " seconds." << std::endl;
  startPortScan(targetIP, timeout);

  return 0;
}
