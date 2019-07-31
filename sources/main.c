#include <unistd.h>
#include "ft_ssl.h"

int main(int argc, char * const *argv)
{
	int res;

	res = md5(argc, argv);
	if (res != 0) {
		ft_printf("Something going wrong\n");
	}
	return 0;
}
