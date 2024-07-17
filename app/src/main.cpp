#include <stdio.h>
#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>

#define CONFIG_BOARD "nRF52840"

int main()
{
   printk("Hello World! %s\n", CONFIG_BOARD);

   while (true)
   {
      k_msleep(1000);
   }

   return 0;
}
