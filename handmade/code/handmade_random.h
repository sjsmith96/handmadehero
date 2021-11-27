#if !defined(HANDMADE_RANDOM_H)
/* ========================================================================
   $File: $
   $Date: $
   $Revision: $
   $Creator: Casey Muratori $
   $Notice: (C) Copyright 2014 by Molly Rocket, Inc. All Rights Reserved. $
   ======================================================================== */

// TODO: Random number generator!
global_variable uint32 RandomNumberTable[] =
{
    0x19ffbca, 0x5e8cd82, 0x22424fb, 0x36f522d,	0x3c22ebd, 0x181ce6b, 0x5ec24a8, 0x47dd433,
    0x14e92f1, 0x368ff43, 0x09eb8f0, 0x0844771,	0x25418c1, 0x322f512, 0x25d37ea, 0x2aebeec,
    0x0d81877, 0x1a7f963, 0x482a12f, 0x56d52b0,	0x038c58e, 0x3b8aa10, 0x4eb763d, 0x4902523,
    0x593458e, 0x48d6a53, 0x0764930, 0x3ca29d5,	0x18993b3, 0x205cea6, 0x0a2b993, 0x302eaa5,
    0x200e476, 0x048e85a, 0x2713f37, 0x36f401b,	0x5e60623, 0x0ed8b67, 0x377f12a, 0x2c78924,
    0x190d556, 0x27fc556, 0x43fa075, 0x53cada8,	0x1416350, 0x0bafaaf, 0x52de07c, 0x5017ced,
    0x5d729b2, 0x01425b7, 0x2d5b263, 0x28a39c8,	0x2d1f5cb, 0x462cdf1, 0x564b86e, 0x1918519,
    0x3434c8e, 0x5df56f0, 0x183d7de, 0x461a286,	0x2a3ff66, 0x5de642e, 0x3373549, 0x2452c88,
    0x25e82bb, 0x1d0f451, 0x21f4021, 0x2c79625,	0x3e28228, 0x3267365, 0x56039cb, 0x3a696fe,
    0x00efb11, 0x21ca5c3, 0x4c1377e, 0x5c34593,	0x2196234, 0x1cbe338, 0x178ff34, 0x18a3a44,
    0x2a27a59, 0x356a759, 0x3d2032b, 0x41e2a6f,	0x327c234, 0x265e651, 0x37c0fb3, 0x0eb13c9,
    0x2a52c83, 0x3c8e4c6, 0x1cf28b2, 0x392aed7,	0x23dc6ac, 0x3802289, 0x0bd98a2, 0x5c2db6e,
    0x226a813, 0x57eea83, 0x35b087e, 0x5c2562c,	0x306ccc2, 0x199068d, 0x09e5e0d, 0x2d30f8b,
    0x2e51239, 0x5785c40, 0x5c05f68, 0x31af05d,	0x28be6d2, 0x44248a9, 0x02f5fd0, 0x007b384,
    0x295bf8b, 0x5e48bc7, 0x2946c59, 0x43c9943,	0x4033cd0, 0x0cd38d4, 0x26198fe, 0x53d9619,
    0x47cffdf, 0x3f923cc, 0x27911a3, 0x28cab12,	0x187f8d3, 0x05ad52e, 0x5d5c125, 0x1c5e8b0,
    0x451e3c6, 0x4260be2, 0x3fc4bf5, 0x564e995,	0x165acd6, 0x0d84ec7, 0x08c00ce, 0x2f14d28,
    0x0350ea5, 0x30a03e2, 0x410d98b, 0x04069df,	0x57bf893, 0x4230142, 0x2771869, 0x12d3988,
    0x4179155, 0x29fc49d, 0x355438e, 0x18012ee,	0x1d55e7e, 0x4070c5c, 0x059a72c, 0x226cb00,
    0x45bfd21, 0x0718c71, 0x204541a, 0x389ef67,	0x1b34c1e, 0x17254c6, 0x5d82232, 0x21ad3cb,
    0x4357403, 0x580e60a, 0x547a5af, 0x3c50fe2,	0x2cf823a, 0x096c28d, 0x2e90106, 0x00d6c6a,
    0x0de739a, 0x3702474, 0x2a755b4, 0x3904e05,	0x1fe4752, 0x1e78f17, 0x3117b77, 0x2df851a,
    0x19da9c7, 0x42db114, 0x05a3be3, 0x4faf7f7,	0x45d8b66, 0x53e6122, 0x5df07a0, 0x26ccfcf,
    0x55f7dab, 0x4c96bed, 0x007a8ec, 0x0072630,	0x0b4bd46, 0x1ad7bf1, 0x0ed079c, 0x4eb17b0,
    0x3b38c12, 0x019bf46, 0x59baffd, 0x1f4212d,	0x00b5a0d, 0x3cc6b16, 0x4d30f06, 0x366c74b,
    0x403eafd, 0x0750f5a, 0x4970aa7, 0x137b46f,	0x50d1b56, 0x16a7c32, 0x25f0f31, 0x0d7160f,
    0x46d137f, 0x34f88e3, 0x37fadf0, 0x3e54524,	0x1661dab, 0x329b8a8, 0x2bc7aef, 0x0e67042,
    0x0de1472, 0x1d1a942, 0x16a7d80, 0x105c598,	0x55517e7, 0x5f0590d, 0x2b94253, 0x0065fc2,
    0x34cc205, 0x2d8362e, 0x0f3a7d5, 0x38d6a98,	0x5ecb399, 0x2dedc37, 0x31eafc2, 0x4bab677,
    0x2cfa07b, 0x1b12f6c, 0x3f88893, 0x38eb1a7,	0x38b2ba2, 0x37e164e, 0x4357c79, 0x44d4510,
    0x4a959dc, 0x15015f3, 0x4565878, 0x43c6bec,	0x0d87a54, 0x50308cd, 0x1e7ee8b, 0x4145a79,
    0x5b4bfd4, 0x41daa7d, 0x35d5555, 0x55111e5,	0x032e8a6, 0x00a4556, 0x0312361, 0x3d06c87,
    0x1535c74, 0x5292069, 0x5b380b2, 0x1d3c8ea,	0x2ec659d, 0x073f36e, 0x3165c13, 0x0852d3a,
    0x0b8e95f, 0x24ac24f, 0x5c2cec9, 0x22b9e97,	0x4390d9e, 0x59b7e80, 0x081aac7, 0x0cfa1cd,
    0x25a4879, 0x51b4769, 0x4f0f70b, 0x431407b,	0x563a8b9, 0x5c945be, 0x58f5d00, 0x4bee409,
    0x191bc6c, 0x476485d, 0x2d77436, 0x5862ff8,	0x108bebb, 0x00b3577, 0x116c47d, 0x23bc51d,
    0x073d030, 0x412c564, 0x0b2ff6d, 0x5774442,	0x226f1c6, 0x3f033fc, 0x01692d2, 0x2e91e37,
    0x3c0f3a7, 0x45c9731, 0x209cbb2, 0x1176401,	0x54891c8, 0x31b744d, 0x5af3208, 0x4f364bc,
    0x48de53f, 0x2593b90, 0x59ca6bb, 0x4adceb9,	0x3d36424, 0x244cc32, 0x2d71dd7, 0x2e84c11,
    0x04dbaa5, 0x4d3e713, 0x3c27dcc, 0x0214140,	0x08165af, 0x1786140, 0x0c6ac3b, 0x1e2f465,
    0x4dbe1d9, 0x28aa6ef, 0x0c7df4a, 0x568ef6b,	0x1250cab, 0x4bb610d, 0x1852ef9, 0x284322d,
    0x563cf89, 0x1f3d289, 0x0a16c62, 0x4e57101,	0x08cc3fc, 0x287f57c, 0x3cae89c, 0x1595c76,
    0x547e217, 0x28caf94, 0x2757945, 0x0f431cc,	0x036c088, 0x58a7630, 0x1520e93, 0x2d6bc6f,
    0x57d9d8e, 0x0a3b5cf, 0x1876411, 0x3f688c7,	0x305b310, 0x0789cf6, 0x0a2af4a, 0x2124b56,
    0x2faf2f2, 0x59fc73b, 0x2a9e848, 0x2fe06f9,	0x0bbcc2d, 0x0ee0099, 0x12af579, 0x16c3738,
    0x1ef8c50, 0x086e6cf, 0x02025a4, 0x0b1d1e6,	0x2de2561, 0x0110ddd, 0x5bb3ae0, 0x12395d1,
    0x3ea1d8a, 0x1d706ea, 0x3c0a4af, 0x111af96,	0x06bcc76, 0x510e78f, 0x0a6a707, 0x122d453,
    0x0e54e43, 0x192d979, 0x3036d30, 0x083e0cd,	0x50c0a3f, 0x5d34b91, 0x4446be8, 0x5521617,
    0x13fb2fe, 0x03032a6, 0x1785841, 0x2c9b42d,	0x53265ea, 0x2ff5d61, 0x5beafc8, 0x08a1c3d,
    0x582df82, 0x1d2c878, 0x2623413, 0x407a6e7,	0x0660469, 0x14c5133, 0x5687631, 0x34d9fbb,
    0x2bfc3f9, 0x3a15e07, 0x19b2fa4, 0x0e40a00,	0x091fe7d, 0x4b81b95, 0x066bc91, 0x3e227e8,
    0x44a904c, 0x4ca63f0, 0x1460918, 0x16c323b,	0x568a8aa, 0x3760fce, 0x543dd82, 0x541d90b,
    0x17ea338, 0x24a2180, 0x01e4dce, 0x26f6d59,	0x367faf5, 0x2bfd092, 0x4d2bf4c, 0x2e7929e,
    0x0bc12d1, 0x303d121, 0x3a04f0e, 0x118d4d3,	0x3c5af5d, 0x0b0f252, 0x204d337, 0x3fa8adc,
    0x1c808c5, 0x56c7dab, 0x0d32dd7, 0x487bba4,	0x047b8b2, 0x1d2ca11, 0x090a302, 0x0c39202,
    0x0c93f4f, 0x09f9f82, 0x36ecc71, 0x5c7166f,	0x24ab819, 0x450cc55, 0x5d50f73, 0x5f011f9,
    0x1a5e18f, 0x567bbe7, 0x5235da8, 0x0254ce3,	0x0634086, 0x006ae42, 0x0e9a1a6, 0x2e803e4,
    0x0835882, 0x1cb34fe, 0x2ecc9b1, 0x13332d3,	0x5e8991c, 0x14201d7, 0x4f4fd7c, 0x5319519,
    0x1e1ebfe, 0x3bcb495, 0x465a8bc, 0x0c6e782,	0x2b08a58, 0x5a5b609, 0x413942f, 0x41d6325,
    0x0e4b718, 0x3a4ac0e, 0x31c83b6, 0x216dc80,	0x545af18, 0x1a43a33, 0x3bacc0a, 0x27f5010,
    0x44ba0b0, 0x54ec06f, 0x0023de4, 0x1ef04e8,	0x00f5b86, 0x166a475, 0x383b817, 0x0126f84,
    0x0e767fc, 0x0c3f07c, 0x4f52de2, 0x396c5c2,	0x23d37b1, 0x1a400c3, 0x2f1d074, 0x4fe369b,
    0x2d2cec7, 0x28882c5, 0x0d83dc2, 0x49c9adc,	0x3ae4c6f, 0x43ae2d9, 0x5abbae7, 0x3e1ab5e,
    0x06432db, 0x091578e, 0x0aa12b9, 0x4efa694,	0x4404580, 0x4683511, 0x5a1617b, 0x196037f,
    0x30eda70, 0x1c3c273, 0x507d9dd, 0x0509990,	0x197cdef, 0x2432a50, 0x2dbc1d1, 0x549fff2,
    0x2206d0f, 0x206e952, 0x422377f, 0x1ac07fb,	0x5d4c190, 0x4e224b1, 0x1c29d81, 0x2dd9f2e,
    0x0c99f82, 0x4e9f4c6, 0x1bd0e9f, 0x48b483c,	0x2d6aeec, 0x022fb48, 0x21392d8, 0x5461e24,
    0x06d2c3f, 0x2ad2337, 0x5934209, 0x18b0ca2,	0x0e6a4ed, 0x196f80e, 0x5d5010f, 0x14c7b0e,
    0x51b1559, 0x515e919, 0x3ea08b2, 0x262e2cf,	0x2acaafc, 0x1dc18b0, 0x32b3d5e, 0x58d899e,
    0x0161696, 0x4e200ce, 0x2e745be, 0x56291b1,	0x1044410, 0x5b333e1, 0x3382332, 0x46354e0,
    0x00cc085, 0x00b6513, 0x04cfb04, 0x2f036ae,	0x4d875e9, 0x419c9bd, 0x124fb2b, 0x4839a14,
    0x0d07142, 0x0528bed, 0x121568e, 0x25ec52f,	0x1a74c6b, 0x2e84abd, 0x1f4504a, 0x38c5b5c,
    0x3a45281, 0x58387f4, 0x5479e29, 0x41141de,	0x35214b2, 0x022e32d, 0x27336e2, 0x2bcbd6b,
    0x5263327, 0x52c9ed3, 0x4a0450e, 0x5849a45,	0x5d32d2e, 0x54b0017, 0x2576f42, 0x2ff6961,
    0x1cf19bb, 0x39d7e3a, 0x2108ae5, 0x564673b,	0x28c3bba, 0x3864bb3, 0x4791b6c, 0x1620ab7,
    0x368d4b0, 0x3a4403c, 0x2261b0d, 0x326f0f2,	0x39aee7d, 0x408c7ce, 0x164413c, 0x253946d,
    0x186b649, 0x35e1b96, 0x0860d02, 0x2a2c522,	0x5b64b4a, 0x3cb2283, 0x1ba9be8, 0x38fbc9d,
    0x4234b5b, 0x15ac7b6, 0x297127f, 0x3237141,	0x2566e08, 0x5dceb99, 0x3d9093d, 0x21fa228,
    0x16eee2f, 0x3c25fd1, 0x318fcdb, 0x23d6664,	0x22b8038, 0x48bc66b, 0x091b6c5, 0x3de7692,
    0x5c0de42, 0x52f9630, 0x4a283dc, 0x4bf5643,	0x53d68d0, 0x59fac73, 0x050a50b, 0x5d56bbb,
    0x5095165, 0x0320cb2, 0x5b995cd, 0x226459e,	0x54e03a7, 0x5766585, 0x5ba2bd0, 0x0ba1dc0,
    0x31bfb49, 0x0405563, 0x0a0a028, 0x4b382d1,	0x1dfadca, 0x4a37837, 0x1ab74d5, 0x1d37504,
    0x303d11e, 0x5377e6d, 0x52cea19, 0x515b2df,	0x55e9986, 0x31ec819, 0x4004027, 0x5862a49,
    0x2fd1d6a, 0x23e888e, 0x30f0b1c, 0x5e0d7d1,	0x5ca3fe2, 0x3b0f2e5, 0x5aee6c6, 0x1e1e00c,
    0x5e87378, 0x02dd6c0, 0x3359e55, 0x0b34f63,	0x186312b, 0x1e816cb, 0x134b8c5, 0x5dbfc14,
    0x59fc793, 0x430e04d, 0x3bf52ca, 0x50b1bc3,	0x0316fc0, 0x1c835f5, 0x3564073, 0x3d4fd94,
    0x2e96b00, 0x34540f0, 0x565b334, 0x4a1ccf8,	0x3e5560b, 0x4026e7d, 0x4368c23, 0x022a28e,
    0x0697f9c, 0x10e474e, 0x1241e36, 0x21bc323,	0x202ee40, 0x47e557f, 0x56b25b2, 0x4dec0b2,
    0x4843c9d, 0x2550d6a, 0x5c8c2b9, 0x1ad34ee,	0x0d27eb9, 0x1e999a8, 0x0da0dd0, 0x331d939,
    0x24a5684, 0x32875bc, 0x5b6046c, 0x42c5a56,	0x1dc9400, 0x2e2cf22, 0x181166b, 0x0511d15,
    0x4bf0e5d, 0x5495188, 0x14ae62e, 0x44f2225,	0x1eb5d3a, 0x4b2f8af, 0x19868d8, 0x1817786,
    0x016e686, 0x0440aa1, 0x5d8afa1, 0x2c969ef,	0x22c6e90, 0x20a2a90, 0x576933e, 0x4695cf5,
    0x006f3ed, 0x1a9006e, 0x0dbec74, 0x5e777fe,	0x310d427, 0x0247848, 0x3507e65, 0x350fc55,
    0x530a3f6, 0x1a1eef8, 0x30aaab1, 0x04de631,	0x1470426, 0x1164f5e, 0x5c36573, 0x509f3e1,
    0x20bed3a, 0x55f2f8e, 0x17ff0bb, 0x01866e2,	0x4ef345b, 0x188f38d, 0x32cab2c, 0x105e495,
    0x382af4d, 0x261ca74, 0x0e90684, 0x0d81d5b,	0x17ed48b, 0x0c4bacf, 0x2dca234, 0x01e1a9f,
    0x1f430e8, 0x57f80cc, 0x4cecde5, 0x24d5a7c,	0x5ce2b11, 0x255ff86, 0x3bf901e, 0x3626b01,
    0x5983c82, 0x44364e5, 0x1ba8cfd, 0x5c72931,	0x03893bc, 0x0a9641b, 0x59b00a7, 0x1755985,
    0x244f4f2, 0x5c1d487, 0x3c19c0b, 0x3d00e27,	0x5f2d9db, 0x4c22547, 0x1e8c0fd, 0x01cf02f,
    0x20cfe6e, 0x1d019e2, 0x0d2d586, 0x420ea0c,	0x0ed4ebe, 0x496625a, 0x029f271, 0x27815bd,
    0x1f142d7, 0x2132824, 0x50269d8, 0x03ad5f2,	0x097901b, 0x32a2b52, 0x5496759, 0x1f1c64b,
    0x3124297, 0x3694142, 0x46207e7, 0x3b6267a,	0x021f3a8, 0x2295040, 0x291c77d, 0x0df243a,
    0x15e2572, 0x2ce0f9c, 0x2ead0f6, 0x56a5eee,	0x00e2178, 0x59db036, 0x0ee1b38, 0x091e7a7,
    0x430fd45, 0x5898055, 0x28b971a, 0x1d91c2b,	0x1cb4c21, 0x01b0241, 0x44fe0c0, 0x4a1b9d5,
    0x5ba5bc0, 0x59e1eb9, 0x38698e0, 0x166972c,	0x4b1f8b4, 0x1ba0b7b, 0x527e048, 0x4b2e86c,
    0x4411a8a, 0x386f75f, 0x1ca7a08, 0x3eebf92,	0x45ee333, 0x472c476, 0x3a5a87b, 0x464342b,
    0x250cae2, 0x129cdea, 0x5e5750f, 0x52b73fd,	0x0ab4daf, 0x1c24dc3, 0x58d203b, 0x397ab21,
    0x133aaa4, 0x49b87cd, 0x104fcbe, 0x2e80044,	0x1f2be93, 0x12665e5, 0x1780ab2, 0x35c9fbb,
    0x5f5b38b, 0x0f2f3ea, 0x35fc951, 0x471624b,	0x544d3dc, 0x0186bd3, 0x15492ce, 0x412b719,
    0x3d2c9aa, 0x3609545, 0x3ec30ae, 0x3bfa64f,	0x4cb35c2, 0x1b2ef87, 0x37088d4, 0x15919d1,
    0x4c90bf0, 0x43bace0, 0x5f10615, 0x1742d6b,	0x4ee7890, 0x53e304a, 0x5438e24, 0x3f1d33a,
    0x0c1d14e, 0x4003e95, 0x1d7b180, 0x37b17ce,	0x38d6159, 0x0e85df2, 0x46f3853, 0x51541de,
    0x1f926fc, 0x08bf822, 0x32df412, 0x3a5ad53,	0x28c0a00, 0x4fd12a7, 0x5105cd8, 0x4110f71,
    0x220529f, 0x1b5dce0, 0x1b3627a, 0x2cf0632,	0x34599b8, 0x1eea6fd, 0x4d37663, 0x0195031,
    0x1686c3d, 0x5531ebc, 0x5b67aa1, 0x2fa5acb,	0x545ef6f, 0x3da359b, 0x062e068, 0x1317c5e,
    0x59747e5, 0x2210721, 0x3874c07, 0x5c925af,	0x2e022d8, 0x1282264, 0x456d376, 0x06e3a99,
    0x1f7ec71, 0x145eff9, 0x5ea5227, 0x009d984,	0x31b5034, 0x5dd63a3, 0x2f6d59f, 0x591c390,
    0x4f5c16c, 0x16c640c, 0x4d4d438, 0x52dcf0e,	0x10eac36, 0x198a9ed, 0x25ad393, 0x114ef39,
    0x18d429e, 0x5f4fdb8, 0x4f3aa68, 0x03a0f10,	0x4d83f7c, 0x30fbd08, 0x1b8ae3b, 0x3aa7def,
    0x5349654, 0x5c301b8, 0x34c8b22, 0x3ba81b7,	0x0eed2a0, 0x2f72826, 0x201ca6e, 0x1567f20,
    0x48ebc46, 0x1791600, 0x5244b61, 0x25a73bf,	0x4a71535, 0x276af2e, 0x0fd2560, 0x13632c0,
    0x01e6d03, 0x5195d50, 0x56a261f, 0x0e798ff,	0x157b633, 0x41b2fa8, 0x522c7b3, 0x43d0963,
    0x4dd6072, 0x2c9b4a1, 0x37f5e84, 0x411cb64,	0x4291ea1, 0x432966e, 0x581d933, 0x53e23ff,
    0x46f82f6, 0x3e94e10, 0x2a5037d, 0x28a0393,	0x49bca97, 0x1b6e557, 0x304b6eb, 0x2a73a06,
    0x46e7f38, 0x1f9b78f, 0x4308926, 0x0d841e5,	0x08b412b, 0x5e180e1, 0x38e562d, 0x2a72a16,
    0x35ab34c, 0x400fee0, 0x40ac99e, 0x3595867,	0x5635a37, 0x4f64eec, 0x3b0d76d, 0x1301d87,
    0x3e315cc, 0x09017d6, 0x49c8a01, 0x0eb66a7,	0x3d0669a, 0x17e5cbc, 0x20c4bbb, 0x107a2df
};

#define HANDMADE_RANDOM_H
#endif
