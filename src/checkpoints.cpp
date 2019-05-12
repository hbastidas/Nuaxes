// Copyright (c) 2009-2012 The Bitcoin developers
// Copyright (c) 2018 The Nuaxes developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <boost/assign/list_of.hpp> // for 'map_list_of()'
#include <boost/foreach.hpp>

#include "checkpoints.h"

#include "txdb.h"
#include "main.h"
#include "uint256.h"


static const int nCheckpointSpan = 10;

namespace Checkpoints
{
    typedef std::map<int, uint256> MapCheckpoints;

    //
    // What makes a good checkpoint block?
    // + Is surrounded by blocks with reasonable timestamps
    //   (no blocks before with a timestamp after, none after with
    //    timestamp before)
    // + Contains no strange transactions
    //
    static MapCheckpoints mapCheckpoints =
        boost::assign::map_list_of
        (0, uint256("0x00000d63e8cf1f6894a67eb143655fba6c6fda0cfb6c066e38acc908ca38162d"))
        (1000, uint256("0x00000000000000711c6e9d71d01da2828fa1a3b1e9b85142f4ad400ba991259e"))
        (2000, uint256("0x00000000000002ad95a520413f8a71664caf133023d239f2d538c6a6018d5efa"))
        (3000, uint256("0x000000000000027348979e05e9adaf61ba9e88aed166f8755407441a5d85039d"))
        (4000, uint256("0x0c5fecd333116bd1a5f302a112eaac8a0fe951891fb9ecb8cbc4ffc1fb550dc8"))
        (5000, uint256("0x5d20c703c24ab47f5cc9d0001623325cc4813f9b170af0fe8de11a08ddc358db"))
        (6000, uint256("0x65abd227c0fcf079f50829cf87aed85ade858a239e545140ae600eac7250fdae"))
        (7000, uint256("0x00000000000000b3c1ba5bc56874d89cfa8581f14210acbafb8adbe8bc027fc5"))
        (8000, uint256("0x000000000000024c4ebdf6dd8feab714dba9e8fbd86c1f870f690ea285ddf452"))
        (9000, uint256("0x000000000000046ab901ef6db1306a31b7038bc9261220593e647ad36e89b15c"))
        (10000, uint256("0x00000000000000297495bd19aca11f35074bf01b4d66ff08565de56651bf4d04"))
        (11000, uint256("0x7085eb3a1e88aa27bba48a96fe4d7ec3047f6ea415c1e75ee4959335b9f138a8"))
        (12000, uint256("0xbb9cfce45863e7ecf90607e9591cb3c15c2a71cc365dc8c133d33a20f492767b"))
        (13000, uint256("0x21d2f08d413600f87ca18bebd043f4e02889ec7c4d7379ae3a85854c260652dd"))
        (14000, uint256("0x0000000000000198c2646368fdaa1dd7d6ccba6d5cb810316db9639e249ffd43"))
        (15000, uint256("0x0000000000000777d7a785c74e88d83ddff099f679220cc9d5d880fc04d47c97"))
        (16000, uint256("0x00000000000003a3a9f4cd54af5fc25131ea64b8b049653ad329ddc9e8236009"))
        (17000, uint256("0x9ff79c34e13e6418b575af272d93e1f6ce1cbcc12ad2de5df814e44066ca5c27"))
        (18000, uint256("0x00000000000005879786b2fc52c02865bb1ed1b099df598a5222bc55025f4f5e"))
        (19000, uint256("0x24ee400ac1711439a8706cb0cccc0166fce6528316ccf0afad7e0fc82c9b8bae"))
        (20000, uint256("0x000000000000083e20ce813459856508caae1f430ea8cdf468765b3bf8a01213"))
        (21000, uint256("0x4c65e4bad636ab8bcbe1ee093dcafa8298d251ab6e0798346433e7c09e38edb6"))
        (22000, uint256("0x000000000000091c191a0213452abaf698ca3b029da589b4e69d9643ef74ce70"))
        (23000, uint256("0x00000000000004daa629b77c5627e2014162010851714003a9a072eeaaa2a50d"))
        (24000, uint256("0x802c0dd383b765a1c2b861697341c31da12926115f03b9e5d63f86976f894415"))
        (25000, uint256("0x00000000000000893e7c93d3634ee2ef8f530c8c8dac0ff30929bd75eb361146"))
        (26000, uint256("0x00000000000000b3dbe9a1287f90fb2fcd9c1cd124a493d54cd302599b77066b"))
        (27000, uint256("0x00000000000008875bb11a0d8d2f6b79b3fa37e63948b75fe07799b7800080e6"))
        (28000, uint256("0x00000000000005a2bad1c9ca4830e811a4fca704f2795ae79f26a1a107b9da18"))
        (29000, uint256("0x000000000000082790d143d70cebc9b03e3955f8e8526bef1e383f8e2d2a0ae4"))
        (30000, uint256("0xb77712106f667990901e8d1ad39d9b1c7075e9c84d6bf187d6b98ea022705df4"))
        (31000, uint256("0x00000000000005eaed84748c405978baeb2d600a49d68dc56e4a76ebdeda6898"))
        (32000, uint256("0x5f9cca68f066ac878b1c0bfce05da7194e8722e8fa7258245961f70e3fb8a733"))
        (33000, uint256("0x0000000000000422a08757266eb7db55333f38b64f8df5b3b5680a6249f6565f"))
        (34000, uint256("0xc2b80ffc8a84f58b5b453aca1d09eb8c42be748cf8c172adf1d2a8c759ecd4d0"))
        (35000, uint256("0x000000000000002ce5032b2b05eb674b74aca99657e4cbc6a4d07cab1998bec5"))
        (36000, uint256("0x0000000000000677677605fb383a335a6ca279d70f3b2a276c51ac5f97a7025c"))
        (37000, uint256("0x0e51f30155857f499316b17171d14fec1d33333fc5000471eca17d49e36c61c1"))
        (38000, uint256("0xec0e527687e7ff558964ffecb8128019860699c12e70ac25c1751b392f21e459"))
        (39000, uint256("0xb79a39101c64b5114c891f3d3bba6392962b3f36876c60c290bddfa4e4a6fde9"))
        (40000, uint256("0x00000000000000a857324474b72881a6d0a6c3d7e48ba60883c29c236b5882ba"))
        (41000, uint256("0x000000000000055600ff00e7144cd835986c7957152582f3263c65bb1744ce26"))
        (42000, uint256("0x0000000000000814bd3b9515f0a4de067c47feae1429f9cbcd8a422d7c7249ca"))
        (43000, uint256("0x00000000000007368afb0c26c1fc06776c198e50a519328abf85f372db743122"))
        (44000, uint256("0x00000000000008a5ce559094f8d348e587ec8d4558df42f92b23ba21d678899f"))
        (45000, uint256("0x7102546580f67d3497c55139af71261fda3cbbcda793a22e614c4b37f593c36f"))
        (46000, uint256("0x0000000000000cfd0418d3c03b6b2e5604bf36048f05b1a536fafc541d1261ef"))
        (47000, uint256("0x0000000000000b31c24f4d408fb531389b2c7ce580e6e5e83f5ab309f8798d3a"))
        (48000, uint256("0x00000000000005fc7acd2ab8c39eac0c8eed4ed96cc838c80da6591b6e199437"))
        (49000, uint256("0x00000000000007585d809745271256452ff90545adb69631f088be2bead0a72d"))
        (50000, uint256("0xd633a6cb167224d8109d6d110dd6535652ba166e09e8d02cba3507470382d0d1"))
        (51000, uint256("0xf1ca40020a43aa4a30c8feac026ef36a2e077c55b230841bb4552b5a489791bd"))
        (52000, uint256("0x00000000000014e1a5c312767899d79bd336759dc318e40407334a44ea215157"))
        (53000, uint256("0x000000000000090014254b754eeeb2ee1273e335db9163a2345d757c5b235543"))
        (54000, uint256("0x0000000000000476c188b71502c87e4266939ccbcf0dc73e011c6c09e7209dcd"))
        (55000, uint256("0xdf6671e498500c7b85d28d16ee668b54e437a02f337f93f95583bacbc130f200"))
        (56000, uint256("0x0000000000000df15555884dcf800d58641ea3275e3d80a8ed7a3591850232b8"))
        (57000, uint256("0x32f1b1f539b1a85ab586e30f960190330dd1d0618a785346c80266cd9b710a6a"))
        (58000, uint256("0xf4f9c37d24130157a58ae457d3eaa06bd77eee414f7279a66c403f89d11f583f"))
        (59000, uint256("0x0000000000001465b4ce8bdd55a7b47b863906b01f8b530793dc451c1f85e7d5"))
        (60000, uint256("0x000000000000010cf92e52a902a362db366633db4acf097180e1479d0f9bfb1f"))
        (61000, uint256("0x24fed9f0860d5f5969199400e6cd797b43449e6c7a7882c76f06453a26498e5a"))
        (62000, uint256("0x7de4247285b17bf63612fccc7ec7238b2e72f9eca4866558cc4fb5165869caa6"))
        (63000, uint256("0xccffe5f319b572500fa4260e8ca43bef66ff14e6f14a20b6eb339dc30daa69d2"))
        (64000, uint256("0x6b9ed0e7090a745af123275ec23711fb585178355ad28da038b208585eb02ec7"))
        (65000, uint256("0x384dd6355b6b397184ed785205e4217876d771c5254f87283809acb9bf19fb25"))
        (66000, uint256("0xe29e366fd7c4f9bdb4ab499c4c4d6ebe41bf179f6aa49ad7728de8175bc49f90"))
        (67000, uint256("0x4e472c2d4157fd4775fd4c34a287c322c1ac022fbb493d08080dbc4f4b6bc932"))
        (68000, uint256("0x88269f6326cca824708fc1c8466b3c85475af11978f01e8435ddd257da60ce5b"))
        (69000, uint256("0xbf2646870a68b6af8471338b4a9717c45f65aa2d5af5007c665e5182e400a9e1"))
        (70000, uint256("0xd1a813671eaefc6dd8b623a45f693913c89111ad525907b12865da3833790626"))
        (71000, uint256("0xc25abbd84e9a133bec36fd281735c2e68d3ebec20f250f609a9960790716738b"))
        (72000, uint256("0x84a4831fd8c21eb1d262e69fda37c4ae54d005009c7699d1b8612870e407be46"))
        (73000, uint256("0xae7fdf41e712804e77f0f6d004f1fe1c47b304545a8c9b8497c20b062534a3a3"))
        (74000, uint256("0x4d5c927b9d543a03a7218feb2518cf5f7dd3481ec4c9a22b0f5ed776b48a94dc"))
        (75000, uint256("0x4ae57617675136cedcb886d153ad0ec32c1d71b61fd160fc6181dcfccf4d2b23"))
        (76000, uint256("0xa676754b5b9880e2c41afd63b729fb932e3dcbae234394a4bd81c9aef406c739"))
        (77000, uint256("0x56c2cc7d658b05ca39197fa8eb28898c60acb671a740e2f47097c6226722426a"))
        (78000, uint256("0x5131675616b9bdb02f9c12357d0cdc40759352e4d86760110d6a365311ac01f5"))
        (79000, uint256("0x5095a6bc242ce9a72644f7447c4f777428cb052971dc336827f8d73e890bff96"))
        (80000, uint256("0x66c1b6ea82cdb11e198e53f47fb3fe275f1b949b8addb3178312eb310247b05f"))
        (81000, uint256("0x4e1ee65c775aa16076dbf9972f129258781f47997343bb13bde5c6794aac003c"))
        (82000, uint256("0x82bcbc76874ca9b963c226224ee91b326daeca6fafb33255f77f29d5fe8c9292"))
        (83000, uint256("0xd5c3665b7bfb7008a86b61893ca48f0350916dd236e5a5bd331d15c819077344"))
        (84000, uint256("0x54323e83d18297a11b6aa2e32dfa21b9fa4ec52cf571e9cb7e5ddeb5c19201d5"))
        (85000, uint256("0xc8f456be83aa37522496722f326a368321d6d04ee393caadce6750a04881e75f"))
        (86000, uint256("0xb09fb41ea5dec92ca08878c231cabc16908425f171d8045a8c3d902c3ce46c79"))
        (87000, uint256("0xe711fa1cf9b2d7e280f73b5b7b02eb1598be8049fe710ddf301976482941f3db"))
        (88000, uint256("0xdb8395a17f610a1db0bb65ae9501dcbb9bdc15e8b3f9780eb5acf4184799e460"))
        (89000, uint256("0x7edf9ab382d475e1d30cdddbab88968c16d7de9126cef6e0f7e2648ebc9be8c9"))
        (90000, uint256("0x88c3cefc26f5defd89c47bca9f885755a0517a8eedd3551d4e275a8deab1920d"))
        (91000, uint256("0x29f19f659929584836bb4df77b408786c74af3eea5914d86961b1d19c40835e7"))
        (92000, uint256("0x32d6bf627ef81e326df37d3d4320fa3e54c80c242da0f153fd4b246a5a3a061b"))
        (93000, uint256("0x5d96dfcf09f57e6498589eba8417d51c0f59088f0dae9630b0cefa1259609db8"))
        (94000, uint256("0x7fb448c15ac1e4e3af70a62e4c43f0c86a924094df0e7ec198c7b7142c776c89"))
        (95000, uint256("0x3878863fa96a92bd7cdd7b036c830b55ab2b3867fec6f514288944ca3839ad83"))
        (96000, uint256("0x77c8b2061fcad5b53ffaae205e6c49a917d2af6330ffe7fd2a29c180d81d0e1f"))
        (97000, uint256("0x3984e27cae5926cc5bc2fa34e7c0c91839c60a8e5fa79895ae0f90f83de7dd05"))
        (98000, uint256("0x308dc7b1c60c63332c8467cd5388c36ef098bff6f17904a817c784453d8b6632"))
        (99000, uint256("0xc736fec9d442d615741bf8df77612ec713d0c86ffede6fac37c12fa368115ec3"))
        (100000, uint256("0xb01443e9ab87d7dc040f87e4a9f73c55a6bc18ee9c759b882007ab104a58661d"))
        (101000, uint256("0xac95dd1e2f223c4a457d5a05ac1fcbdcb09be75145a3102591993318019b7764"))
        (102000, uint256("0xf00584ce089dddbace28cfd242bd49f10837c8c2be7fab81a0b728f78e20fe96"))
        (103000, uint256("0xee7e8559d00563f1b882262b4c721c249367fdab7c9b35e78c32b7275aed5a02"))
        (104000, uint256("0x4267585bc7d45a546fd6f48695e5e743a5673cc0b380b5dc9694740493cc4019"))
        (105000, uint256("0xf82c7bdee2b1bc200cb0f9c2cdffc881d3955674cc39f4a4a70327e08162618e"))
        (106000, uint256("0x34dbdb6fe86125802600db3694f9ac8984f25b419e960bdaa92a674f33edab10"))
        (107000, uint256("0x458bcc4f067a0dbe3275719a97a34270b74498f105a507e4f4d459b5a3318a20"))
        (108000, uint256("0xe09b59e0fe5ecd031f09d7b653e4d9a6c67008460f3e0cd63992a68b05dc90d3"))
        (109000, uint256("0xc72631b764d84372fc4c533aaddf09f0d80236ecb4f9a5b0839cfbd608a8c1ed"))
        (110000, uint256("0xaeeb3f87399abc3e21119e4986cb94f62b050978f879ffd13cf8349d48ab4908"))
        (111000, uint256("0xd32e25be5f50fe894ec4f8bcc3a3065c01d0385c567791dfa9d357ef9ddf9984"))
        (112000, uint256("0xc4bcb772aeb79115ee72cdb806b2902c7050e0b4377f4629cd16ea8dc6441084"))
        (113000, uint256("0xb441630092f346731e2f48faff11079366e27e7b7041c3b32cf182c7b351667b"))
        (114000, uint256("0xa56fb7c82a292177727843dcd24bbc070a639c602d1a380e4bc0727acba13b95"))
        (115000, uint256("0x48c334d58116483684b525f6dfb99f9617098f18bf0bbc6d5f0dcf42ab6297ac"))
        (116000, uint256("0x2a4d2c027ac578f2e179c14cbf8b5d7e7d9053325cbc701a9084454f4db76670"))
        (117000, uint256("0xe2d4800c60d86c11170990084b7d8999580a99d99ebea1c98540923e795764b8"))
        (118000, uint256("0x10367894771b6929ed8a1150613194b51d06a7ecff5682d50f8f3f9140fffbcf"))
        (119000, uint256("0xc49f3aede941e26b59d88ffa11fd66c546bb4568a315108b5da8ff90f336d7a5"))
        (120000, uint256("0x5590cb4903ff0355c1553f85c66113407842521213cef66735a0889c1e337b30"))
        (121000, uint256("0xb9f01d40a9fa8bdcce7767a3f623c996837238a744b25a38e83ca89416e3aa2e"))
        (122000, uint256("0xb44cfe5ad936d2c887740a8b7bf6919069946953f65e08b5ac42e86191a9109a"))
        (123000, uint256("0x69d05b7e7d4ad238edafd0606a76fc53dd816b62f959672c3950b8ef9d3bdfd8"))
        (124000, uint256("0x6b97b20a38df17ebdf15431132f25efdc2a8f8a40c942cb44addc5816979e6d3"))
        (125000, uint256("0xc3906ca676816fcaec0453e3119e3df01e4fc218aa7710a276af4d2ba04eaac0"))
        (126000, uint256("0x11c943d6d1fce530a02ba3f4755060c2f5c7edc9d2540a1c8b060d8be2773486"))
        (127000, uint256("0xd983139900f3e38842106d59357a0ff65570bb7737230c7c8e4eb0170c6ff7b4"))
        (128000, uint256("0x200f7e4968e08bcd3d17e9c674c2a7e6a80b2255e610f4a1748c4110a4312903"))
        (129000, uint256("0x99e7ebbfea7f28d132414e2895bacd4c9a374c8b7ae36bef2fc25b5677c0de5d"))
        (130000, uint256("0x339ceeec2ab93e467651276ead3d074cdda4f8d8b95b9dd52853e47f84163871"))
        (131000, uint256("0x4888b2cb4091215f4e187349ebed6c07d3880c11e585c1ead808c3ff7768bc8d"))
        (132000, uint256("0xcfdef9162a58d446ce079d32ab6461e9bb1ec343c554d664a2f8835be2508afd"))
        (133000, uint256("0x1882a7425bf20e7d6b5cbd94d953f7ef01fe86935f75b341d05299bd1f000124"))
        (134000, uint256("0xc94af8dc42e242dd43a85af0ef105071bcbe27721a67f355c68670bad7674591"))
        (135000, uint256("0xe94a552ca764d677db73051b4a3115b1cc0f9e128909e3df0b0e7771a1e2ed13"))
        (136000, uint256("0xa6f6082cfa970de8215e2c9597011dbfe46e5088b736c801e436e50307c22b20"))
        (137000, uint256("0xc7f4041cdd6902a9af92b221a367974985c97f7f52bc586a57bfb0c6994e378e"))
        (138000, uint256("0x1307757d3feb1a9368c2c27ac873c4a4282d86f2e5cf25f9c75cf4e218bcfb39"))
        (139000, uint256("0x53c35d347bdd3b8a88c04b0254cae7ae9044528f5df4397a1ddbdbce09c25091"))
        (140000, uint256("0x0acff82282567729502778402a51078f4a94cbad8da8c308de034a12f9a61c03"))
        (141000, uint256("0xbc18ed2047036c9e5d090bb57c253dc838b602e8e65639d892e13393da577c4d"))
        (142000, uint256("0xafa248a7c884804ceec15609a33da08733bd03bc380e611146ef12ff3e1f9635"))
        (143000, uint256("0x5f402a980456357706c32d5e6a6fd532fa326bf4b19f619f040e93d3e06aeae8"))
        (144000, uint256("0x02671f3d8229ada7db0987d85595cf1d94e9ce479fba0e06c518c5678f0b3e7c"))
        (145000, uint256("0x257ba90a41809b442f94172f6418673be3219d07d2fe369534cf92a675abd2d7"))
        (146000, uint256("0x09da1f37061ddf049b66fd080046cad6aedcd63ad23a4ca7d7a8701ba41eedcd"))
        (147000, uint256("0x090fd1810e2a0dce6546b8275bd6a327849ca75a800bf59ca314f805352365a8"))
        (148000, uint256("0xc9cd44ad8a82097c201fa25d480a38e0ddbc9ae8e0b209d86a6f047068f9dd8b"))
        (149000, uint256("0xd9df7d4fe7061d64f3a802295d894bce631a05473b705a6e59048cee65647f4b"))
        (150000, uint256("0xa25a5984ab54f8856cb47d823bd515b511c1d2ce2c74a331e6cff727b9a042b7"))
        (151000, uint256("0xf97f09bb88b475de36f61bcec0b44a45571fd4b455b6e119f6a68bce4bd151fc"))
        (152000, uint256("0x9ae7447d73655d553c8e028ac6ac4c1eb18a655d308290ce73c8d76c0fad374a"))
        (153000, uint256("0x90758d939a6279cd7a34c6aa8a1f7fc912051f12caf67b6fb09330af1995ddf3"))
        (154000, uint256("0x20a42cf5a0a69a69da1c9b8cfe4601f6e85ac5e871008da33946787c523d6453"))
        (155000, uint256("0xe2f4f4d8ec8b3bdf6bea991fd2658e2f8f3cf3b28be026c1d42159bfb0398b77"))
        (156000, uint256("0x265b7f023a1bc73e8d29d9003e7b83864094240568697281bdd5d5883ba3b933"))
        (157000, uint256("0x8bcf0e9028f57081629af93602a9eaa2cc780a3cb45bd64350bbfe9300c2f6b8"))
        (158000, uint256("0xb45c7234966693e9b9833dbcece23d060612370efce69625019beb33a6c19c23"))
        (159000, uint256("0xc45a169229a5cccf7ae3e64149e4836f8926193ede66b83c0179feb146b2e3cb"))
        (160000, uint256("0xe52c11abadc1d6e3da21fc9201a8f4c9df23ac84f92734a5cf57f8cecf494d46"))
        (161000, uint256("0x68a5674e1344f2e563aaa308e7b61f46a5f6ffcb2270f7f8868251eb6037ba77"))
        (162000, uint256("0x4bc79c0bb67470373f98bb567776ba01ec0a7d52980c26826c249e329b647e37"))
        (163000, uint256("0xda321c0182261882133c8baa1eaceccac5339e0dbf6d91dbe22537eca333fead"))
        (164000, uint256("0x2b8f2626ba61f6d586cd473de587d99ce517018250accbc19eec2c2146ce81fe"))
        (165000, uint256("0x1dbc8d60d9669d409ed13e0e9b88d93b0b83038c3719f07b529cae41933c7289"))
        (166000, uint256("0xa4f982d63de10ff3b5a374d76832c86e776298592af849db353a0de752dd0752"))
        (167000, uint256("0x10a3796dfc3d9b4595a99c5db9067febbe0a584ae3abb6fab5ec34789bd58f8b"))
        (168000, uint256("0x3fa91a6cd7e78f60ec3e398ca57ca9cc0b65ee66feb26bd17b80c7adbf885f50"))
        (169000, uint256("0xb44ea8a8fdef73a23d46b0b0b064b0eb5633d7341889c97ca6e2a6b6c633bd59"))
        (170000, uint256("0xd62698045d03af651a238b1b2c56741a67e6447007640ae97101a2fc013b9d25"))
        (171000, uint256("0x94bea8154a852a25eba715b18e1dc6b2a80a682dfcc2ae6d7262db78d9d24daf"))
        (172000, uint256("0x40cb3a3ae8c4ed2ce5f1a87656070ac3a956569a2faf7d926bdf2d108496aa51"))
        (173000, uint256("0x8496105bfb969b9150b2bc0f15751a68fec298c78b2fdbf0866d2ec3b3a33f1c"))
        (174000, uint256("0x0dc237d87017921380b3d07dc5fc7615cbce0689fd9273d9ddc1c5ddbfef6e5f"))
        (175000, uint256("0xf01adbc50ef13f6f74c3873a81afa1b34a9e36214f822d422d31c409b2b61fa1"))
        (176000, uint256("0x066a125cb5bc04cec2be9a6e57c3b2ed4f56ab33966e6f9d9f4982f48324084a"))
        (177000, uint256("0xea8e5c350081449a2cf662c55cb2bd7437c99a7d25d49a8466c9cd01993514c5"))
        (178000, uint256("0x1b840ffc700ea39ab33a2c6b1ea807a6c0b0cf46159cd3ae21bf66f0c2dba90c"))
        (179000, uint256("0x3794e7117d744089167937bb1773defe25b7cc59e8e08de0d815253bdc336eed"))
        (180000, uint256("0x29b0e25ef2205e069592ddd0762eba85f4aca3e102c770d413e1b02e0269b8e8"))
        (181000, uint256("0x0c2ae65622c6a215687dde448c8d8f0ed6c55081ef2ead3495a9d87465fd729c"))
        (182000, uint256("0x1f1bb13c1deba88797d22dc24a30de5f9da6c47255a18c57c8dccdde49b9aea8"))
        (183000, uint256("0x9d5393ba4dc2d9802ff96a28acec29878ab14c823729bdbc686fef9a22f55a82"))
        (184000, uint256("0xabfee8e8553f4f72f97a80a96c48502d4853bdd7a6f85bdad13b8ce08c44d8bf"))
        (185000, uint256("0x2a05dc48df98d03e64d44e353a14a3fe47e7413d73256773be9ce339729b4ec4"))
        (186000, uint256("0x464b81817bb3a2a8b79e38f920260784059c7ce68b030444c7eece7117fc63ba"))
        (187000, uint256("0x5f31eda7fb3d53823bdbfa4569e0ee173d7e93aef4c5624c1e6f3f04c5401531"))
        (188000, uint256("0x4363208a843f9aadc0d0b0b140d53c91613d611c6db3c8b3b1c363f5a74fb9f2"))
        (189000, uint256("0xaa06c011b243eab6b051062ee00af7720f0da7cb37f69d71df3fb65398cc3021"))
        (190000, uint256("0xd9838af75ea731f3d006688d95a18056edd95919678d0533c12ff2dc19e9c3ed"))
        (191000, uint256("0xaff6ae07202d4916d767f2b4738f9abb2bbdfb424ff8d55a39671e1869a63f1e"))
        (192000, uint256("0x382a67d66801cf62735a29eef5eddcc48ef365bc6b7e23572d62e1787e404a89"))
        (193000, uint256("0xaed416623725af5ff3affd6292aa8fe1201a9e35217402dc39ed47c04bc67359"))
        (194000, uint256("0xe1f1bf3a9657ee305cbe2448b25c862e0528e5ad0466e45f8ca24c96e4d73d9b"))
        (195000, uint256("0x64b3639e94af30c90a6a5a8d3ea498acda0f07aa09003723e9bfc1ce8e7e9804"))
        (196000, uint256("0x539f4dd4ec17c5d326b18da345f04553d3042a6c58f37bf342145fc47cf7a21d"))
        (197000, uint256("0xbb3d055c5ee0a9c7d66a36c31fa5718b6ebbfee437456048b4687a1a1bfeae55"))
        (198000, uint256("0xac9cd7504e8035a98efaf88565f264a039a3422660982d06792fcf3f211baba0"))
        (199000, uint256("0xb523dee78390abe5970d740db2bcd15eb89f85ab77cca8c066f6edf22925769d"))
        (200000, uint256("0x4382c5ef9ddf6f0d3900b81f13b6538434a0bcc2d29df7fde71e82c317cfed23"))
        (201000, uint256("0xe50e0e4a225c18d716b7ff6789388149dbd49d63ae7643961c05bad731fe2b7a"))
        (202000, uint256("0x5f12992c862fac8421cb860964710928d31c152b23e0d1021b8578a0489447a9"))
        (203000, uint256("0x95d8a6052a070662a7b524502b3558a0d342ee31699ba0a7a4f1ff1789f0bac9"))
        (204000, uint256("0xe504cff0aaffc9606e87a988c2bd22ae573b61c017a008bb68bd92cd43ecf5d6"))
        (205000, uint256("0xc4e30c62b180cdb2e65ac8f5bd209423899118fbbd6118867234720470438b29"))
        (206000, uint256("0x34db1454af5a6f270dc923f85d25b616b06e0e7069ca902101620c9b5bbc7390"))
        (207000, uint256("0x6e803a3e203a96e83c8a5cc73916e8d3493b97e0ecdabf5f23279cf7127f74fb"))
        (208000, uint256("0xd60982e2583971748425aab0a0ce44e754e82d0af6951638947658d8614c9eff"))
        (209000, uint256("0x6f50fa2ca9c20bbfed5a54f5b5566a047c02b635eeeb33f37b48ac87978ac707"))
        (210000, uint256("0xddf8496ae5e64e05bed6c54bc6fbf8193892d0ff67e188bfb1d4b6352fb78619"))
        (211000, uint256("0xa500ffc9a789bc15cb2eb04aeab5d3d8272ed81b2a50638d3510b80cb75a45da"))
        (212000, uint256("0x8f4e11077418c92bf0db28bb1bc79bbba716b5da9c5113880487ad9e333f26ed"))
        (213000, uint256("0x015b28a2e8aabafb9d32e60cfbe31539d7ea53a94660ae7eb06459ef33ae7509"))
        (214000, uint256("0x9d1f300cb3284f679a51ddeb312663994b31ae15d99e66f8703aa1c7ac8357fe"))
        (215000, uint256("0xa0307b3c83a30387342c745b85121f1b2b05196e73fea464c5130f39ee2cd354"))
        (216000, uint256("0x9734e8d1ec7edd55e8b30ce31cd7aa0c899d044a792052575f703edd6b969a59"))
        (217000, uint256("0xdf77a9cc4c720a8b8cb26460207b00d22ae3bd54c0bb01213eb3fc274bf9dc3d"))
        (218000, uint256("0xaf42ac15eafb100b236daef99922add1de90c2be6b35521376af7787f2d6fbf2"))
        (219000, uint256("0xaec8fc70e80c2353e48259f663a8c19a0158c4de4261f05fbee55e1755bd03de"))
        (220000, uint256("0x555151fdc4474f791f2585a26411d2ba02037c298f7cc956930dec44da12f08f"))
        (221000, uint256("0x31fd2b81bf946d1a6633d7a7c12ee434de24efc6cd3c95340d0767b471848787"))
        (222000, uint256("0xe2074120936fc4c522712b763aa0f7d1a7cdcc9566fd2fffa0744026f54927f1"))
        (223000, uint256("0x88c73ecd34c504e530123922d2ad16259318949b6cc577198bd149bf91aead42"))
        (224000, uint256("0x3318539cafa48733616f166ffc76ece5e98adb2ca3621c612fff305acdf55788"))
        (225000, uint256("0xcc255d34de1d83191a4482ac1df6306310a1dc9a4ad144818d94400800e3bf99"))
    ;

    // TestNet has no checkpoints
    static MapCheckpoints mapCheckpointsTestnet =
        boost::assign::map_list_of
        ( 0, hashGenesisBlockTestNet )
        ;

    bool CheckHardened(int nHeight, const uint256& hash)
    {
        MapCheckpoints& checkpoints = (fTestNet ? mapCheckpointsTestnet : mapCheckpoints);

        MapCheckpoints::const_iterator i = checkpoints.find(nHeight);
        if (i == checkpoints.end()) return true;
        return hash == i->second;
    }

    int GetTotalBlocksEstimate()
    {
        MapCheckpoints& checkpoints = (fTestNet ? mapCheckpointsTestnet : mapCheckpoints);

        return checkpoints.rbegin()->first;
    }

    CBlockIndex* GetLastCheckpoint(const std::map<uint256, CBlockIndex*>& mapBlockIndex)
    {
        MapCheckpoints& checkpoints = (fTestNet ? mapCheckpointsTestnet : mapCheckpoints);

        BOOST_REVERSE_FOREACH(const MapCheckpoints::value_type& i, checkpoints)
        {
            const uint256& hash = i.second;
            std::map<uint256, CBlockIndex*>::const_iterator t = mapBlockIndex.find(hash);
            if (t != mapBlockIndex.end())
                return t->second;
        }
        return NULL;
    }

    // Nuaxes: synchronized checkpoint (centrally broadcasted)
    uint256 hashSyncCheckpoint = 0;
    uint256 hashPendingCheckpoint = 0;
    CSyncCheckpoint checkpointMessage;
    CSyncCheckpoint checkpointMessagePending;
    uint256 hashInvalidCheckpoint = 0;
    CCriticalSection cs_hashSyncCheckpoint;

    // Nuaxes: get last synchronized checkpoint
    CBlockIndex* GetLastSyncCheckpoint()
    {
        LOCK(cs_hashSyncCheckpoint);
        if (!mapBlockIndex.count(hashSyncCheckpoint))
            error("GetSyncCheckpoint: block index missing for current sync-checkpoint %s", hashSyncCheckpoint.ToString().c_str());
        else
            return mapBlockIndex[hashSyncCheckpoint];
        return NULL;
    }

    // Nuaxes: only descendant of current sync-checkpoint is allowed
    bool ValidateSyncCheckpoint(uint256 hashCheckpoint)
    {
        if (!mapBlockIndex.count(hashSyncCheckpoint))
            return error("ValidateSyncCheckpoint: block index missing for current sync-checkpoint %s", hashSyncCheckpoint.ToString().c_str());
        if (!mapBlockIndex.count(hashCheckpoint))
            return error("ValidateSyncCheckpoint: block index missing for received sync-checkpoint %s", hashCheckpoint.ToString().c_str());

        CBlockIndex* pindexSyncCheckpoint = mapBlockIndex[hashSyncCheckpoint];
        CBlockIndex* pindexCheckpointRecv = mapBlockIndex[hashCheckpoint];

        if (pindexCheckpointRecv->nHeight <= pindexSyncCheckpoint->nHeight)
        {
            // Received an older checkpoint, trace back from current checkpoint
            // to the same height of the received checkpoint to verify
            // that current checkpoint should be a descendant block
            CBlockIndex* pindex = pindexSyncCheckpoint;
            while (pindex->nHeight > pindexCheckpointRecv->nHeight)
                if (!(pindex = pindex->pprev))
                    return error("ValidateSyncCheckpoint: pprev null - block index structure failure");
            if (pindex->GetBlockHash() != hashCheckpoint)
            {
                hashInvalidCheckpoint = hashCheckpoint;
                return error("ValidateSyncCheckpoint: new sync-checkpoint %s is conflicting with current sync-checkpoint %s", hashCheckpoint.ToString().c_str(), hashSyncCheckpoint.ToString().c_str());
            }
            return false; // ignore older checkpoint
        }

        // Received checkpoint should be a descendant block of the current
        // checkpoint. Trace back to the same height of current checkpoint
        // to verify.
        CBlockIndex* pindex = pindexCheckpointRecv;
        while (pindex->nHeight > pindexSyncCheckpoint->nHeight)
            if (!(pindex = pindex->pprev))
                return error("ValidateSyncCheckpoint: pprev2 null - block index structure failure");
        if (pindex->GetBlockHash() != hashSyncCheckpoint)
        {
            hashInvalidCheckpoint = hashCheckpoint;
            return error("ValidateSyncCheckpoint: new sync-checkpoint %s is not a descendant of current sync-checkpoint %s", hashCheckpoint.ToString().c_str(), hashSyncCheckpoint.ToString().c_str());
        }
        return true;
    }

    bool WriteSyncCheckpoint(const uint256& hashCheckpoint)
    {
        CTxDB txdb;
        txdb.TxnBegin();
        if (!txdb.WriteSyncCheckpoint(hashCheckpoint))
        {
            txdb.TxnAbort();
            return error("WriteSyncCheckpoint(): failed to write to db sync checkpoint %s", hashCheckpoint.ToString().c_str());
        }
        if (!txdb.TxnCommit())
            return error("WriteSyncCheckpoint(): failed to commit to db sync checkpoint %s", hashCheckpoint.ToString().c_str());

        Checkpoints::hashSyncCheckpoint = hashCheckpoint;
        return true;
    }

    bool AcceptPendingSyncCheckpoint()
    {
        LOCK(cs_hashSyncCheckpoint);
        if (hashPendingCheckpoint != 0 && mapBlockIndex.count(hashPendingCheckpoint))
        {
            if (!ValidateSyncCheckpoint(hashPendingCheckpoint))
            {
                hashPendingCheckpoint = 0;
                checkpointMessagePending.SetNull();
                return false;
            }

            CTxDB txdb;
            CBlockIndex* pindexCheckpoint = mapBlockIndex[hashPendingCheckpoint];
            if (!pindexCheckpoint->IsInMainChain())
            {
                CBlock block;
                if (!block.ReadFromDisk(pindexCheckpoint))
                    return error("AcceptPendingSyncCheckpoint: ReadFromDisk failed for sync checkpoint %s", hashPendingCheckpoint.ToString().c_str());
                if (!block.SetBestChain(txdb, pindexCheckpoint))
                {
                    hashInvalidCheckpoint = hashPendingCheckpoint;
                    return error("AcceptPendingSyncCheckpoint: SetBestChain failed for sync checkpoint %s", hashPendingCheckpoint.ToString().c_str());
                }
            }

            if (!WriteSyncCheckpoint(hashPendingCheckpoint))
                return error("AcceptPendingSyncCheckpoint(): failed to write sync checkpoint %s", hashPendingCheckpoint.ToString().c_str());
            hashPendingCheckpoint = 0;
            checkpointMessage = checkpointMessagePending;
            checkpointMessagePending.SetNull();
            printf("AcceptPendingSyncCheckpoint : sync-checkpoint at %s\n", hashSyncCheckpoint.ToString().c_str());
            // relay the checkpoint
            if (!checkpointMessage.IsNull())
            {
                BOOST_FOREACH(CNode* pnode, vNodes)
                    checkpointMessage.RelayTo(pnode);
            }
            return true;
        }
        return false;
    }

    // Automatically select a suitable sync-checkpoint
    uint256 AutoSelectSyncCheckpoint()
    {
        const CBlockIndex *pindex = pindexBest;
        // Search backward for a block within max span and maturity window
        while (pindex->pprev && (pindex->GetBlockTime() + nCheckpointSpan * nTargetSpacing > pindexBest->GetBlockTime() || pindex->nHeight + nCheckpointSpan > pindexBest->nHeight))
            pindex = pindex->pprev;
        return pindex->GetBlockHash();
    }

    // Check against synchronized checkpoint
    bool CheckSync(const uint256& hashBlock, const CBlockIndex* pindexPrev)
    {
        if (fTestNet) return true; // Testnet has no checkpoints
        int nHeight = pindexPrev->nHeight + 1;

        LOCK(cs_hashSyncCheckpoint);
        // sync-checkpoint should always be accepted block
        assert(mapBlockIndex.count(hashSyncCheckpoint));
        const CBlockIndex* pindexSync = mapBlockIndex[hashSyncCheckpoint];

        if (nHeight > pindexSync->nHeight)
        {
            // trace back to same height as sync-checkpoint
            const CBlockIndex* pindex = pindexPrev;
            while (pindex->nHeight > pindexSync->nHeight)
                if (!(pindex = pindex->pprev))
                    return error("CheckSync: pprev null - block index structure failure");
            if (pindex->nHeight < pindexSync->nHeight || pindex->GetBlockHash() != hashSyncCheckpoint)
                return false; // only descendant of sync-checkpoint can pass check
        }
        if (nHeight == pindexSync->nHeight && hashBlock != hashSyncCheckpoint)
            return false; // same height with sync-checkpoint
        if (nHeight < pindexSync->nHeight && !mapBlockIndex.count(hashBlock))
            return false; // lower height than sync-checkpoint
        return true;
    }

    bool WantedByPendingSyncCheckpoint(uint256 hashBlock)
    {
        LOCK(cs_hashSyncCheckpoint);
        if (hashPendingCheckpoint == 0)
            return false;
        if (hashBlock == hashPendingCheckpoint)
            return true;
        if (mapOrphanBlocks.count(hashPendingCheckpoint)
            && hashBlock == WantedByOrphan(mapOrphanBlocks[hashPendingCheckpoint]))
            return true;
        return false;
    }

    // Nuaxes: reset synchronized checkpoint to last hardened checkpoint
    bool ResetSyncCheckpoint()
    {
        LOCK(cs_hashSyncCheckpoint);
        const uint256& hash = mapCheckpoints.rbegin()->second;
        if (mapBlockIndex.count(hash) && !mapBlockIndex[hash]->IsInMainChain())
        {
            // checkpoint block accepted but not yet in main chain
            printf("ResetSyncCheckpoint: SetBestChain to hardened checkpoint %s\n", hash.ToString().c_str());
            CTxDB txdb;
            CBlock block;
            if (!block.ReadFromDisk(mapBlockIndex[hash]))
                return error("ResetSyncCheckpoint: ReadFromDisk failed for hardened checkpoint %s", hash.ToString().c_str());
            if (!block.SetBestChain(txdb, mapBlockIndex[hash]))
            {
                return error("ResetSyncCheckpoint: SetBestChain failed for hardened checkpoint %s", hash.ToString().c_str());
            }
        }
        else if(!mapBlockIndex.count(hash))
        {
            // checkpoint block not yet accepted
            hashPendingCheckpoint = hash;
            checkpointMessagePending.SetNull();
            printf("ResetSyncCheckpoint: pending for sync-checkpoint %s\n", hashPendingCheckpoint.ToString().c_str());
        }

        BOOST_REVERSE_FOREACH(const MapCheckpoints::value_type& i, mapCheckpoints)
        {
            const uint256& hash = i.second;
            if (mapBlockIndex.count(hash) && mapBlockIndex[hash]->IsInMainChain())
            {
                if (!WriteSyncCheckpoint(hash))
                    return error("ResetSyncCheckpoint: failed to write sync checkpoint %s", hash.ToString().c_str());
                printf("ResetSyncCheckpoint: sync-checkpoint reset to %s\n", hashSyncCheckpoint.ToString().c_str());
                return true;
            }
        }

        return false;
    }

    void AskForPendingSyncCheckpoint(CNode* pfrom)
    {
        LOCK(cs_hashSyncCheckpoint);
        if (pfrom && hashPendingCheckpoint != 0 && (!mapBlockIndex.count(hashPendingCheckpoint)) && (!mapOrphanBlocks.count(hashPendingCheckpoint)))
            pfrom->AskFor(CInv(MSG_BLOCK, hashPendingCheckpoint));
    }

    bool SetCheckpointPrivKey(std::string strPrivKey)
    {
        // Test signing a sync-checkpoint with genesis block
        CSyncCheckpoint checkpoint;
        checkpoint.hashCheckpoint = !fTestNet ? hashGenesisBlock : hashGenesisBlockTestNet;
        CDataStream sMsg(SER_NETWORK, PROTOCOL_VERSION);
        sMsg << (CUnsignedSyncCheckpoint)checkpoint;
        checkpoint.vchMsg = std::vector<unsigned char>(sMsg.begin(), sMsg.end());

        std::vector<unsigned char> vchPrivKey = ParseHex(strPrivKey);
        CKey key;
        key.SetPrivKey(CPrivKey(vchPrivKey.begin(), vchPrivKey.end())); // if key is not correct openssl may crash
        if (!key.Sign(Hash(checkpoint.vchMsg.begin(), checkpoint.vchMsg.end()), checkpoint.vchSig))
            return false;

        // Test signing successful, proceed
        CSyncCheckpoint::strMasterPrivKey = strPrivKey;
        return true;
    }

    bool SendSyncCheckpoint(uint256 hashCheckpoint)
    {
        CSyncCheckpoint checkpoint;
        checkpoint.hashCheckpoint = hashCheckpoint;
        CDataStream sMsg(SER_NETWORK, PROTOCOL_VERSION);
        sMsg << (CUnsignedSyncCheckpoint)checkpoint;
        checkpoint.vchMsg = std::vector<unsigned char>(sMsg.begin(), sMsg.end());

        if (CSyncCheckpoint::strMasterPrivKey.empty())
            return error("SendSyncCheckpoint: Checkpoint master key unavailable.");
        std::vector<unsigned char> vchPrivKey = ParseHex(CSyncCheckpoint::strMasterPrivKey);
        CKey key;
        key.SetPrivKey(CPrivKey(vchPrivKey.begin(), vchPrivKey.end())); // if key is not correct openssl may crash
        if (!key.Sign(Hash(checkpoint.vchMsg.begin(), checkpoint.vchMsg.end()), checkpoint.vchSig))
            return error("SendSyncCheckpoint: Unable to sign checkpoint, check private key?");

        if(!checkpoint.ProcessSyncCheckpoint(NULL))
        {
            printf("WARNING: SendSyncCheckpoint: Failed to process checkpoint.\n");
            return false;
        }

        // Relay checkpoint
        {
            LOCK(cs_vNodes);
            BOOST_FOREACH(CNode* pnode, vNodes)
                checkpoint.RelayTo(pnode);
        }
        return true;
    }

    // Is the sync-checkpoint outside maturity window?
    bool IsMatureSyncCheckpoint()
    {
        LOCK(cs_hashSyncCheckpoint);
        // sync-checkpoint should always be accepted block
        assert(mapBlockIndex.count(hashSyncCheckpoint));
        const CBlockIndex* pindexSync = mapBlockIndex[hashSyncCheckpoint];
        return (nBestHeight >= pindexSync->nHeight + nCoinbaseMaturity ||
                pindexSync->GetBlockTime() + nStakeMinAge < GetAdjustedTime());
    }
}

// Nuaxes: sync-checkpoint master key
const std::string CSyncCheckpoint::strMasterPubKey = "04e1e9ec6e0e8d0857debd5e1d28c21ad5ac00dc7d63b330db7f4b906de2053d63166f248525e583a9048ec4062ed981808fd0042e63e496e1a5e5f9ea37775a8d";

std::string CSyncCheckpoint::strMasterPrivKey = "";

// Nuaxes: verify signature of sync-checkpoint message
bool CSyncCheckpoint::CheckSignature()
{
    CKey key;
    if (!key.SetPubKey(ParseHex(CSyncCheckpoint::strMasterPubKey)))
        return error("CSyncCheckpoint::CheckSignature() : SetPubKey failed");
    if (!key.Verify(Hash(vchMsg.begin(), vchMsg.end()), vchSig))
        return error("CSyncCheckpoint::CheckSignature() : verify signature failed");

    // Now unserialize the data
    CDataStream sMsg(vchMsg, SER_NETWORK, PROTOCOL_VERSION);
    sMsg >> *(CUnsignedSyncCheckpoint*)this;
    return true;
}

// Nuaxes: process synchronized checkpoint
bool CSyncCheckpoint::ProcessSyncCheckpoint(CNode* pfrom)
{
    if (!CheckSignature())
        return false;

    LOCK(Checkpoints::cs_hashSyncCheckpoint);
    if (!mapBlockIndex.count(hashCheckpoint))
    {
        // We haven't received the checkpoint chain, keep the checkpoint as pending
        Checkpoints::hashPendingCheckpoint = hashCheckpoint;
        Checkpoints::checkpointMessagePending = *this;
        printf("ProcessSyncCheckpoint: pending for sync-checkpoint %s\n", hashCheckpoint.ToString().c_str());
        // Ask this guy to fill in what we're missing
        if (pfrom)
        {
            pfrom->PushGetBlocks(pindexBest, hashCheckpoint);
            // ask directly as well in case rejected earlier by duplicate
            // proof-of-stake because getblocks may not get it this time
            pfrom->AskFor(CInv(MSG_BLOCK, mapOrphanBlocks.count(hashCheckpoint)? WantedByOrphan(mapOrphanBlocks[hashCheckpoint]) : hashCheckpoint));
        }
        return false;
    }

    if (!Checkpoints::ValidateSyncCheckpoint(hashCheckpoint))
        return false;

    CTxDB txdb;
    CBlockIndex* pindexCheckpoint = mapBlockIndex[hashCheckpoint];
    if (!pindexCheckpoint->IsInMainChain())
    {
        // checkpoint chain received but not yet main chain
        CBlock block;
        if (!block.ReadFromDisk(pindexCheckpoint))
            return error("ProcessSyncCheckpoint: ReadFromDisk failed for sync checkpoint %s", hashCheckpoint.ToString().c_str());
        if (!block.SetBestChain(txdb, pindexCheckpoint))
        {
            Checkpoints::hashInvalidCheckpoint = hashCheckpoint;
            return error("ProcessSyncCheckpoint: SetBestChain failed for sync checkpoint %s", hashCheckpoint.ToString().c_str());
        }
    }

    if (!Checkpoints::WriteSyncCheckpoint(hashCheckpoint))
        return error("ProcessSyncCheckpoint(): failed to write sync checkpoint %s", hashCheckpoint.ToString().c_str());
    Checkpoints::checkpointMessage = *this;
    Checkpoints::hashPendingCheckpoint = 0;
    Checkpoints::checkpointMessagePending.SetNull();
    printf("ProcessSyncCheckpoint: sync-checkpoint at %s\n", hashCheckpoint.ToString().c_str());
    return true;
}
