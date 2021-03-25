// SPDX-License-Identifier: GPL-2.0
/*
 * Texas Instruments ASI_VIB2 ADC - I2C
 *
 * Copyright (C) 2015-2017 Texas Instruments Incorporated - http://www.ti.com
 *	Andreas Dannenberg <dannenberg@ti.com>
 *	Andrew F. Davis <afd@ti.com>
 */

#include <linux/init.h>
#include <linux/module.h>
#include <linux/i2c.h>

#include "asi_vib2.h"

static const struct of_device_id asi_vib2_of_match[] = {
	{ .compatible = "asi,asi_vib2", .data = (void *)ASI_VIB2 },
	{ }
};
MODULE_DEVICE_TABLE(of, asi_vib2_of_match);

static int asi_vib2_i2c_probe(struct i2c_client *i2c,
			     const struct i2c_device_id *id)
{
	const enum asi_vib2_type type = (enum asi_vib2_type)id->driver_data;
	int irq = i2c->irq;
	struct regmap *regmap;

	regmap = devm_regmap_init_i2c(i2c, &asi_vib2_regmap);
	if (IS_ERR(regmap))
		return PTR_ERR(regmap);

	return asi_vib2_probe(&i2c->dev, type, irq, regmap);
}

static const struct i2c_device_id asi_vib2_i2c_id[] = {
	{ "asi_vib2", ASI_VIB2 },
	{ }
};
MODULE_DEVICE_TABLE(i2c, asi_vib2_i2c_id);

static struct i2c_driver asi_vib2_i2c_driver = {
	.probe		= asi_vib2_i2c_probe,
	.id_table	= asi_vib2_i2c_id,
	.driver		= {
		.name	= "asi_vib2",
		.of_match_table = asi_vib2_of_match,
	},
};
module_i2c_driver(asi_vib2_i2c_driver);

MODULE_AUTHOR("Andreas Dannenberg <dannenberg@ti.com>");
MODULE_AUTHOR("Andrew F. Davis <afd@ti.com>");
MODULE_DESCRIPTION("ASI_VIB2 ADC I2C Interface Driver");
MODULE_LICENSE("GPL v2");
