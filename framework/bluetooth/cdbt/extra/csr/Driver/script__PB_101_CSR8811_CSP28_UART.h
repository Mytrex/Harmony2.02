//-------------------------------------------------------------------
// DO NOT MODIFY THIS FILE!
// This file was machine generated by the make_patch_script.pl script
//-------------------------------------------------------------------

#ifndef __BTX_CSR_PATCH_SCRIPT_INCLUDED__
#define __BTX_CSR_PATCH_SCRIPT_INCLUDED__

#ifdef __cplusplus
extern "C" {
#endif

// =============================================================================
// 
// CSR tracking information, report this in case of problems:
//   $Revision: #11 $
//   Built Thu Jun  9 08:40:33 2011 GMT
//   Checked-in $DateTime: 2011/06/09 12:02:45 $
//   $File: //depot/bc/gemini-a06/dev/patches/7558/pb-101-csr8811-csp28-uart.psr $
// 
// Patch is for build 7558 gem_5hidproxy_rom_bt4.0_gemA06_1012150332_encr128
// 
// Issues patched: B-100005, B-100879, B-101200, B-101408, B-95841,
//                 B-96287, B-97625, B-98367, B-98721, B-98851, B-99956
// 
// Documentation from pb-101-csr8811-csp28-uart.pb
// -----------------------------------------------
// 
// General purpose patch and PSKEY bundle for CSR8810 A06 CSP Packages.
// 
// Documentation from bt_pskeys.pb
// -------------------------------
// 
// Issues patched: B-99956
// 
// Non-default PSKEY settings aimed at improving Bluetooth performance.
// These are recommended for all users of this device regardless of
// package or application.
// 
// Note that some of these settings may depend on the presence of other
// PSKEYs and/or patches. 
// 
// Documentation from inhibit_trim_during_test.xap
// -----------------------------------------------
// 
// Issues patched: B-95841
// 
// Spur due to periodic trim is seen at 2.446 GHz during Ble transmitter test
// 
// Documentation from send_advert_data_response.xap
// ------------------------------------------------
// 
// Issues patched: B-98367
// 
// When Ble advertising on BlueCore, if LE_SetAdvertisingData or
// LE_SetScanResponseData is issued at the moment of connection, the
// controller may report "connection complete" but not "command complete"
// for the HCI command. This results in the controller accepting no
// further HCI commands.
// 
// Documentation from destroy_afh_if_not_ble_master.xap
// ----------------------------------------------------
// 
// Issues patched: B-98721
// 
// If a LE connection attempt is cancelled on a device that has a SCO
// master link then audio quality can be degraded for about 150ms when
// a LE master connection is subsequently created.
// 
// Documentation from edr_pwr.xap
// ------------------------------
// 
// Issues patched: B-96287
// 
// In radiotest mode, BlueCore7 after BlueCore7-FM may have an elevated
// EDR relative power ratio after a cold reset.
// 
// Documentation from min_le_map_channels.xap
// ------------------------------------------
// 
// Issues patched: B-97625
// 
// When performing Ble operations, a BlueCore device can panic with
// PANIC_ULP_TO_BT_CHANNEL_NUMBER_CONVERSION (0xD0) panic code when
// doing AFH in an environment where there are no known good channels.
// 
// Documentation from ulp_update_window_fix.xap
// --------------------------------------------
// 
// Issues patched: B-98851
// 
// When Bluecore is performing Bluetooth low energy scanning while it is doing
// other BR/EDR operations, rare occurrences of PANIC_LC (panic code 0x15)
// may be noticed depending on scan parameters.
// 
// Documentation from lm_lc_reset.xap
// ----------------------------------
// 
// Issues patched: B-100005
// 
// Bluecore returns FAULT_LC_RESET_FAILED fault code if HCI 
// reset command is issued when multiple links are active.
// 
// Documentation from rt_offset.xap
// --------------------------------
// 
// Issues patched: B-101200
// 
// Frequency locking is slow at the start of radiotest commands.
// 
// Documentation from set_ble_coex_last_priority.xap
// -------------------------------------------------
// 
// Issues patched: B-101408
// 
// When using IEEE 802.11/Bluetooth coexistence, a previous correction to
// Ble / BR-EDR signalling resulted in TXRX operations being signalled as
// separate transactions.
// 
// Documentation from patch_set_rx_config_c.c
// ------------------------------------------
// 
// Issues patched: B-100879
// 
// Radiotest loop back mode fails when packet configuration is set to
// multi-slot types.
// 
// Version information for input files
// -----------------------------------
// 
// Created by patchmaker.pl Revision: #43  Date: 2011/03/03 
// 
// Input file: pb-101-csr8811-csp28-uart.pb
// Depot file: //depot/bc/gemini-a06/dev/patches/7558/pb-101-csr8811-csp28-uart.pb
// File revision: 1
// 
// Input file: pb-101-csp-common.pb
// Depot file: //depot/bc/gemini-a06/dev/patches/7558/pb-101-csp-common.pb
// File revision: 1
// 
// Input file: pb-101-common.pb
// Depot file: //depot/bc/gemini-a06/dev/patches/7558/pb-101-common.pb
// File revision: 7
// 
// Input file: bt_pskeys.pb
// Depot file: //depot/bc/gemini-a06/dev/patches/7558/bt_pskeys.pb
// File revision: 7
// 
// Input file: inhibit_trim_during_test.xap
// Depot file: //depot/bc/gemini-a06/dev/patches/7558/inhibit_trim_during_test.xap
// File revision: 4
// 
// Input file: ../patch_utils.inc
// Depot file: //depot/bc/gemini-a06/dev/patches/patch_utils.inc
// File revision: 1
// 
// Input file: send_advert_data_response.xap
// Depot file: //depot/bc/gemini-a06/dev/patches/7558/send_advert_data_response.xap
// File revision: 3
// 
// Input file: destroy_afh_if_not_ble_master.xap
// Depot file: //depot/bc/gemini-a06/dev/patches/7558/destroy_afh_if_not_ble_master.xap
// File revision: 2
// 
// Input file: edr_pwr.xap
// Depot file: //depot/bc/gemini-a06/dev/patches/7558/edr_pwr.xap
// File revision: 6
// 
// Input file: min_le_map_channels.xap
// Depot file: //depot/bc/gemini-a06/dev/patches/7558/min_le_map_channels.xap
// File revision: 4
// 
// Input file: ulp_update_window_fix.xap
// Depot file: //depot/bc/gemini-a06/dev/patches/7558/ulp_update_window_fix.xap
// File revision: 3
// 
// Input file: lm_lc_reset.xap
// Depot file: //depot/bc/gemini-a06/dev/patches/7558/lm_lc_reset.xap
// File revision: 2
// 
// Input file: rt_offset.xap
// Depot file: //depot/bc/gemini-a06/dev/patches/7558/rt_offset.xap
// File revision: 2
// 
// Input file: set_ble_coex_last_priority.xap
// Depot file: //depot/bc/gemini-a06/dev/patches/7558/set_ble_coex_last_priority.xap
// File revision: 3
// 
// Input file: patch_set_rx_config_c.c
// Depot file: //depot/bc/gemini-a06/dev/patches/7558/patch_set_rx_config_c.c
// File revision: 2
// patch_hardware_0, PSKEY_PATCH50 (0x212c, 8492), 23 words
static const bt_byte packet1[] = {
    H(0x212c, 23, 1), 
    W(0x0002), W(0x7249), W(0x0f1b), W(0x0f16), W(0x01a0), W(0x0f26), W(0x0210), W(0x1222), W(0x0218), W(0xff2b), W(0xff0e), W(0x7200), W(0x4f18), W(0xfa0b), W(0x0014), W(0x0327), W(0x0218), W(0xff2b), W(0xff0e), W(0x5000), W(0x7718), W(0x00e2), W(0xe14a), 

};

// patch_hardware_1, PSKEY_PATCH51 (0x212d, 8493), 50 words
static const bt_byte packet2[] = {
    H(0x212d, 50, 2), 
    W(0x0003), W(0x1dcf), W(0x0017), W(0xe334), W(0x0184), W(0x0820), W(0x0014), W(0x0018), W(0xff2b), W(0xff0e), W(0x6a00), W(0xb818), W(0x009e), W(0x0017), W(0x01a0), W(0xe119), W(0x1000), W(0x2516), W(0xfe27), W(0x1000), W(0x2416), W(0xff27), W(0x0117), W(0x0213), W(0xff0e), W(0xfe9f), W(0x0017), W(0x1f84), W(0x08f4), W(0x1c84), W(0x0d28), W(0xe900), W(0x3215), W(0x0800), W(0x00c4), W(0x08f0), W(0x0114), W(0x0018), W(0xff2b), W(0xff0e), W(0x6a00), W(0xb818), W(0x009e), W(0x0318), W(0xff2b), W(0xff0e), W(0x1e00), W(0xdc18), W(0x00e2), W(0x0a52), 

};

// patch_hardware_2, PSKEY_PATCH52 (0x212e, 8494), 16 words
static const bt_byte packet3[] = {
    H(0x212e, 16, 3), 
    W(0x0002), W(0xe5a8), W(0x04f0), W(0xe900), W(0x3c99), W(0x04f4), W(0x059b), W(0x02f0), W(0xf80f), W(0x0218), W(0xff2b), W(0xff0e), W(0xe600), W(0xae18), W(0x00e2), W(0x72ae), 

};

// patch_hardware_3, PSKEY_PATCH53 (0x212f, 8495), 9 words
static const bt_byte packet4[] = {
    H(0x212f, 9, 4), 
    W(0x0002), W(0x52f1), W(0x0218), W(0xff2b), W(0xff0e), W(0x5300), W(0xfb18), W(0x00e2), W(0x7b7d), 

};

// patch_hardware_4, PSKEY_PATCH54 (0x2130, 8496), 54 words
static const bt_byte packet5[] = {
    H(0x2130, 54, 5), 
    W(0x0002), W(0x6c21), W(0x071b), W(0x7f16), W(0x0184), W(0x0cf0), W(0x0127), W(0x7012), W(0x0023), W(0x6f12), W(0xe315), W(0x0218), W(0xff2b), W(0xff0e), W(0x6d00), W(0xda18), W(0x009e), W(0x0717), W(0x7134), W(0x0127), W(0x071b), W(0x0100), W(0x8116), W(0x0100), W(0x8012), W(0x0327), W(0x0223), W(0x7012), W(0x0023), W(0x6f12), W(0x0417), W(0x0018), W(0xff2b), W(0xff0e), W(0x6200), W(0x3a18), W(0x009e), W(0xe199), W(0x09f0), W(0x0018), W(0xff2b), W(0xff0e), W(0x5e00), W(0x0418), W(0x009e), W(0x0314), W(0xf40f), W(0x0218), W(0xff2b), W(0xff0e), W(0x6d00), W(0x9318), W(0x00e2), W(0xc508), 

};

// patch_hardware_5, PSKEY_PATCH55 (0x2131, 8497), 33 words
static const bt_byte packet6[] = {
    H(0x2131, 33, 6), 
    W(0x0000), W(0xe74b), W(0x081b), W(0x5612), W(0x0009), W(0x08a4), W(0xf821), W(0x091b), W(0x2912), W(0x0009), W(0x0da4), W(0xe015), W(0x01c4), W(0x0027), W(0x0a17), W(0xf811), W(0x0118), W(0xff2b), W(0xff0e), W(0x4600), W(0x6118), W(0x009e), W(0x0114), W(0x0527), W(0x091b), W(0x2912), W(0x0018), W(0xff2b), W(0xff0e), W(0xe700), W(0x4f18), W(0x00e2), W(0x9ebb), 

};

// patch_hardware_6, PSKEY_PATCH56 (0x2132, 8498), 29 words
static const bt_byte packet7[] = {
    H(0x2132, 29, 7), 
    W(0x0002), W(0xe405), W(0x09f4), W(0xe419), W(0x0638), W(0xfa39), W(0x00b2), W(0x0022), W(0xf911), W(0x0130), W(0xf921), W(0xf811), W(0x0130), W(0xf821), W(0x0780), W(0x062c), W(0xfa15), W(0x0134), W(0xfa25), W(0x0018), W(0xf829), W(0xf911), W(0x0218), W(0xff2b), W(0xff0e), W(0xe400), W(0x1818), W(0x00e2), W(0x73ea), 

};

// patch_hardware_7, PSKEY_PATCH57 (0x2133, 8499), 10 words
static const bt_byte packet8[] = {
    H(0x2133, 10, 8), 
    W(0x0004), W(0x7005), W(0x0018), W(0xff2b), W(0xff0e), W(0x7e00), W(0xbb18), W(0x009e), W(0xf90f), W(0x7ca0), 

};

// patch_hardware_8, PSKEY_PATCH58 (0x2134, 8500), 25 words
static const bt_byte packet9[] = {
    H(0x2134, 25, 9), 
    W(0x0001), W(0xd3d8), W(0xe600), W(0x4511), W(0x0223), W(0xe311), W(0x0118), W(0xff2b), W(0xff0e), W(0x3300), W(0x4518), W(0x009e), W(0xe700), W(0x7e99), W(0x04f4), W(0x0213), W(0xe600), W(0x4521), W(0x0118), W(0xff2b), W(0xff0e), W(0xd400), W(0xdc18), W(0x00e2), W(0x798f), 

};

// patch_hardware_9, PSKEY_PATCH59 (0x2135, 8501), 15 words
static const bt_byte packet10[] = {
    H(0x2135, 15, 10), 
    W(0x0002), W(0x911f), W(0xe500), W(0xcc19), W(0x002b), W(0xff14), W(0x4d26), W(0x0017), W(0x0218), W(0xff2b), W(0xff0e), W(0x9100), W(0x2218), W(0x00e2), W(0xdac0), 

};

// patch_hardware_10, PSKEY_PATCH60 (0x2136, 8502), 15 words
static const bt_byte packet11[] = {
    H(0x2136, 15, 11), 
    W(0x0002), W(0x8fde), W(0xe500), W(0xcc15), W(0x0027), W(0xff14), W(0x001b), W(0x4c26), W(0x0218), W(0xff2b), W(0xff0e), W(0x9000), W(0xe118), W(0x00e2), W(0x1f06), 

};

// explicit, PSKEY_ULP_RX_DEMOD_CONFIG (0x2184, 8580), 2 words
static const bt_byte packet12[] = {
    H(0x2184, 2, 12), 
    W(0x2ca0), W(0x4836), 

};

// patch_radiotest_radio_configure, PSKEY_PATCH108 (0x21fc, 8700), 8 words
static const bt_byte packet13[] = {
    H(0x21fc, 8, 13), 
    W(0xfe0b), W(0xe700), W(0x0519), W(0x011a), W(0x0014), W(0x3526), W(0xfe0f), W(0xff6b), 

};

// explicit, PSKEY_BLE_TX_FILTER_CONFIG (0x257a, 9594), 2 words
static const bt_byte packet14[] = {
    H(0x257a, 2, 14), 
    W(0x770c), W(0x0003), 

};

static const bt_byte* const packets[] = {
    packet1,
    packet2,
    packet3,
    packet4,
    packet5,
    packet6,
    packet7,
    packet8,
    packet9,
    packet10,
    packet11,
    packet12,
    packet13,
    packet14
};

#define PACKET_COUNT 14

#ifdef __cplusplus
}
#endif

#endif // __BTX_CSR_PATCH_SCRIPT_INCLUDED__

//-------------------------------------------------------------------
// END OF GENERATED FILE
//-------------------------------------------------------------------