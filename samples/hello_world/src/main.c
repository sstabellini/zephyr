/*
 * Copyright (c) 2012-2014 Wind River Systems, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/timeout_q.h>
#include <zephyr/zephyr.h>

struct _timeout timeout;

static void timer_expired(struct _timeout *t)
{
	uint32_t timestamp = k_cycle_get_32();

	printk("Timer timestamp=%u\n", timestamp);
	z_add_timeout(&timeout, timer_expired, Z_TIMEOUT_MS(5000));
}

void main(void)
{
	z_add_timeout(&timeout, timer_expired, Z_TIMEOUT_MS(5000));
}
