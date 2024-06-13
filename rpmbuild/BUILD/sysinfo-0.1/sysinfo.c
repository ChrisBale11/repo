#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/utsname.h>
#include <sys/types.h>
#include <ifaddrs.h>
#include <arpa/inet.h>
#include <time.h>

// Function to print system uptime
void print_uptime() {
    FILE *uptime_file = fopen("/proc/uptime", "r");
    if (uptime_file == NULL) {
        perror("Failed to open /proc/uptime");
        return;
    }

    double uptime;
    if (fscanf(uptime_file, "%lf", &uptime) != 1) {
        perror("Failed to read uptime");
        fclose(uptime_file);
        return;
    }
    fclose(uptime_file);

    int days = (int)uptime / (60 * 60 * 24);
    int hours = ((int)uptime % (60 * 60 * 24)) / (60 * 60);
    int minutes = ((int)uptime % (60 * 60)) / 60;
    int seconds = (int)uptime % 60;

    printf("System uptime: %d days, %d hours, %d minutes, %d seconds\n", days, hours, minutes, seconds);
}

// Function to print IP addresses of all network interfaces
void print_ip_addresses() {
    struct ifaddrs *ifaddr, *ifa;
    if (getifaddrs(&ifaddr) == -1) {
        perror("getifaddrs");
        exit(EXIT_FAILURE);
    }

    printf("IP addresses:\n");

    for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) {
        if (ifa->ifa_addr == NULL || ifa->ifa_addr->sa_family != AF_INET)
            continue;

        struct sockaddr_in *addr = (struct sockaddr_in *)ifa->ifa_addr;
        char ip_address[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &addr->sin_addr, ip_address, sizeof(ip_address));

        printf("%s: %s\n", ifa->ifa_name, ip_address);
    }

    freeifaddrs(ifaddr);
}

int main() {
    struct utsname buf;
    if (uname(&buf) == -1) {
        perror("uname");
        exit(EXIT_FAILURE);
    }

    printf("System information:\n");
    printf("  System name: %s\n", buf.sysname);
    printf("  Node name: %s\n", buf.nodename);
    printf("  Release: %s\n", buf.release);
    printf("  Version: %s\n", buf.version);
    printf("  Machine: %s\n", buf.machine);

    print_uptime();
    print_ip_addresses();

    return 0;
}
