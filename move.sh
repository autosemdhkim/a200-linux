BUILDROOT_PATH=/home/autosem/workspace/dohoon/buildroot/buildroot-2021.02/output/build/linux-custom
echo buildroot_path=${BUILDROOT_PATH}

sudo cp ${BUILDROOT_PATH}/arch/arm/boot/dts/overlays/asi* ./arch/arm/boot/dts/overlays/
sudo cp ${BUILDROOT_PATH}/arch/arm/boot/dts/overlays/Makefile ./arch/arm/boot/dts/overlays/
sudo cp ${BUILDROOT_PATH}/sound/soc/codecs/asi* ./sound/soc/codecs/
sudo cp ${BUILDROOT_PATH}/sound/soc/codecs/Makefile ./sound/soc/codecs/Makefile
sudo cp ${BUILDROOT_PATH}/sound/soc/codecs/Kconfig ./sound/soc/codecs/Kconfig

