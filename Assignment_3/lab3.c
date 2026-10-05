#include <linux/init.h> 
#include <linux/module.h>
#include <linux/jiffies.h>
#include <linux/ktime.h>

MODULE_LICENSE("Dual BSD/GPL"); 

static unsigned long jiffies_start;
static ktime_t time_start;

static int __init hello_init(void) {
    jiffies_start = jiffies;
    time_start = ktime_get_boottime();
    printk(KERN_ALERT "Hello, world\n");
    printk(KERN_ALERT "Tick time (ms): %d\n", 1000/HZ);
    return 0;
}

static void __exit hello_exit(void) {
    unsigned long jiffies_end = jiffies;
    ktime_t time_end = ktime_get_boottime();
    unsigned long jiffies_diff_ms = ((jiffies_end - jiffies_start) * 1000) / HZ;
    s64 time_diff_ms = ktime_to_ms(ktime_sub(time_end, time_start));

    printk(KERN_ALERT "Goodbye, cruel world\n");
    printk(KERN_ALERT "Time elapsed (jiffies): %lu\n", jiffies_diff_ms);
    printk(KERN_ALERT "Time elapsed (ms): %lld\n", time_diff_ms);
}
 
module_init(hello_init); 
module_exit(hello_exit); 