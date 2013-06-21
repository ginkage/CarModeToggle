#include <sys/socket.h>
#include <unistd.h>
#include <linux/netlink.h>

int main(int argc, char *argv[])
{
	char event[] = "ACTION=change\0DEVPATH=/devices/virtual/switch/dock\0SUBSYSTEM=switch\0SWITCH_NAME=state\0SWITCH_STATE=2";
	int sock = socket(PF_NETLINK, SOCK_DGRAM, NETLINK_KOBJECT_UEVENT);

	if (argc > 1) {
		event[sizeof(event) - 2] = argv[1][0];
	}

	if (sock != -1) {
		struct sockaddr_nl snl;
		struct iovec iov = { event, sizeof(event) };
		struct msghdr msg = { &snl, sizeof(snl), &iov, 1, NULL, 0, 0 };

		memset(&snl, 0, sizeof(struct sockaddr_nl));
		snl.nl_family = AF_NETLINK;
		snl.nl_pid = getpid();
		snl.nl_groups = -1;

		sendmsg(sock, &msg, 0);
		close(sock);
	}

	return 0;
}
