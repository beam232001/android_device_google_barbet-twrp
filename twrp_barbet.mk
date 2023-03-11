#
# Copyright (C) 2023 The Android Open Source Project
# Copyright (C) 2023 SebaUbuntu's TWRP device tree generator
#
# SPDX-License-Identifier: Apache-2.0
#

# Inherit from those products. Most specific first.
$(call inherit-product, $(SRC_TARGET_DIR)/product/core_64_bit.mk)
$(call inherit-product, $(SRC_TARGET_DIR)/product/full_base_telephony.mk)

# Release name
PRODUCT_RELEASE_NAME := barbet
DEVICE_PATH := device/google/barbet

# Inherit some common Aosp stuff.
$(call inherit-product, vendor/twrp/config/common.mk)

# Inherit from barbet device
$(call inherit-product, device/google/barbet/device.mk)

PRODUCT_DEVICE := barbet
PRODUCT_NAME := twrp_barbet
PRODUCT_BRAND := google
PRODUCT_MODEL := Pixel 5a
PRODUCT_MANUFACTURER := google

PRODUCT_GMS_CLIENTID_BASE := android-google

PRODUCT_BUILD_PROP_OVERRIDES += \
    PRIVATE_BUILD_DESC="barbet-user 12 SQ3A.220705.003.A1 8672226 release-keys"

BUILD_FINGERPRINT := google/barbet/barbet:12/SQ3A.220705.003.A1/8672226:user/release-keys
