//    Copyright (c) 2021 udevs
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, version 3.
//
//    This program is distributed in the hope that it will be useful, but
//    WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
//    General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program. If not, see <http://www.gnu.org/licenses/>.

#define PRINT(MSG, ...) fprintf(stdout, MSG, ##__VA_ARGS__)
#define WARNING(MSG, ...) fprintf(stderr, "\033[1;33m"MSG"\033[0m", ##__VA_ARGS__)
#define ERROR(MSG, ...) fprintf(stderr, "\033[1;31m"MSG"\033[0m", ##__VA_ARGS__)

#define WORLD_CAPITAL_COOR_ARRAY @[@[@(43.001525), @(41.023415)],\
	  @[@(34.575503), @(69.240073)],\
	  @[@(60.1), @(19.933333)],\
	  @[@(41.327546), @(19.818698)],\
	  @[@(36.752887), @(3.042048)],\
	  @[@(-14.275632), @(-170.702036)],\
	  @[@(42.506317), @(1.521835)],\
	  @[@(-8.839988), @(13.289437)],\
	  @[@(18.214813), @(-63.057441)],\
	  @[@(-90), @(0)],\
	  @[@(17.12741), @(-61.846772)],\
	  @[@(-34.603684), @(-58.381559)],\
	  @[@(40.179186), @(44.499103)],\
	  @[@(12.509204), @(-70.008631)],\
	  @[@(-35.282), @(149.128684)],\
	  @[@(48.208174), @(16.373819)],\
	  @[@(40.409262), @(49.867092)],\
	  @[@(25.047984), @(-77.355413)],\
	  @[@(26.228516), @(50.58605)],\
	  @[@(23.810332), @(90.412518)],\
	  @[@(13.113222), @(-59.598809)],\
	  @[@(53.90454), @(27.561524)],\
	  @[@(50.85034), @(4.35171)],\
	  @[@(17.251011), @(-88.75902)],\
	  @[@(6.496857), @(2.628852)],\
	  @[@(32.294816), @(-64.781375)],\
	  @[@(27.472792), @(89.639286)],\
	  @[@(-16.489689), @(-68.119294)],\
	  @[@(43.856259), @(18.413076)],\
	  @[@(-24.628208), @(25.923147)],\
	  @[@(-54.43), @(3.38)],\
	  @[@(-15.794229), @(-47.882166)],\
	  @[@(21.3419), @(55.4778)],\
	  @[@(18.428612), @(-64.618466)],\
	  @[@(4.903052), @(114.939821)],\
	  @[@(42.697708), @(23.321868)],\
	  @[@(12.371428), @(-1.51966)],\
	  @[@(-3.361378), @(29.359878)],\
	  @[@(11.544873), @(104.892167)],\
	  @[@(3.848033), @(11.502075)],\
	  @[@(45.42153), @(-75.697193)],\
	  @[@(14.93305), @(-23.513327)],\
	  @[@(19.286932), @(-81.367439)],\
	  @[@(4.394674), @(18.55819)],\
	  @[@(12.134846), @(15.055742)],\
	  @[@(-33.44889), @(-70.669265)],\
	  @[@(39.904211), @(116.407395)],\
	  @[@(-10.420686), @(105.679379)],\
	  @[@(-12.188834), @(96.829316)],\
	  @[@(4.710989), @(-74.072092)],\
	  @[@(-11.717216), @(43.247315)],\
	  @[@(-4.441931), @(15.266293)],\
	  @[@(-4.26336), @(15.242885)],\
	  @[@(-21.212901), @(-159.782306)],\
	  @[@(9.928069), @(-84.090725)],\
	  @[@(6.827623), @(-5.289343)],\
	  @[@(45.815011), @(15.981919)],\
	  @[@(23.05407), @(-82.345189)],\
	  @[@(12.122422), @(-68.882423)],\
	  @[@(35.185566), @(33.382276)],\
	  @[@(50.075538), @(14.4378)],\
	  @[@(55.676097), @(12.568337)],\
	  @[@(11.572077), @(43.145647)],\
	  @[@(15.309168), @(-61.379355)],\
	  @[@(18.486058), @(-69.931212)],\
	  @[@(-0.180653), @(-78.467838)],\
	  @[@(30.04442), @(31.235712)],\
	  @[@(13.69294), @(-89.218191)],\
	  @[@(3.750412), @(8.737104)],\
	  @[@(15.322877), @(38.925052)],\
	  @[@(59.436961), @(24.753575)],\
	  @[@(8.980603), @(38.757761)],\
	  @[@(-51.697713), @(-57.851663)],\
	  @[@(62.007864), @(-6.790982)],\
	  @[@(-18.124809), @(178.450079)],\
	  @[@(60.173324), @(24.941025)],\
	  @[@(48.856614), @(2.352222)],\
	  @[@(4.92242), @(-52.313453)],\
	  @[@(-17.551625), @(-149.558476)],\
	  @[@(-21.3419), @(55.4778)],\
	  @[@(0.416198), @(9.467268)],\
	  @[@(13.454876), @(-16.579032)],\
	  @[@(41.715138), @(44.827096)],\
	  @[@(52.520007), @(13.404954)],\
	  @[@(5.603717), @(-0.186964)],\
	  @[@(36.140773), @(-5.353599)],\
	  @[@(37.983917), @(23.72936)],\
	  @[@(64.18141), @(-51.694138)],\
	  @[@(12.056098), @(-61.7488)],\
	  @[@(16.014453), @(-61.706411)],\
	  @[@(13.470891), @(144.751278)],\
	  @[@(14.634915), @(-90.506882)],\
	  @[@(49.455443), @(-2.536871)],\
	  @[@(9.641185), @(-13.578401)],\
	  @[@(11.881655), @(-15.617794)],\
	  @[@(6.801279), @(-58.155125)],\
	  @[@(18.594395), @(-72.307433)],\
	  @[@(14.072275), @(-87.192136)],\
	  @[@(22.396428), @(114.109497)],\
	  @[@(47.497912), @(19.040235)],\
	  @[@(64.126521), @(-21.817439)],\
	  @[@(28.613939), @(77.209021)],\
	  @[@(-6.208763), @(106.845599)],\
	  @[@(35.689198), @(51.388974)],\
	  @[@(33.312806), @(44.361488)],\
	  @[@(53.349805), @(-6.26031)],\
	  @[@(54.152337), @(-4.486123)],\
	  @[@(32.0853), @(34.781768)],\
	  @[@(41.902784), @(12.496366)],\
	  @[@(18.042327), @(-76.802893)],\
	  @[@(35.709026), @(139.731992)],\
	  @[@(49.186823), @(-2.106568)],\
	  @[@(31.956578), @(35.945695)],\
	  @[@(51.160523), @(71.470356)],\
	  @[@(-1.292066), @(36.821946)],\
	  @[@(1.451817), @(172.971662)],\
	  @[@(42.662914), @(21.165503)],\
	  @[@(29.375859), @(47.977405)],\
	  @[@(42.874621), @(74.569762)],\
	  @[@(17.975706), @(102.633104)],\
	  @[@(56.949649), @(24.105186)],\
	  @[@(33.888629), @(35.495479)],\
	  @[@(-29.363219), @(27.51436)],\
	  @[@(6.290743), @(-10.760524)],\
	  @[@(32.887209), @(13.191338)],\
	  @[@(47.14103), @(9.520928)],\
	  @[@(54.687156), @(25.279651)],\
	  @[@(49.611621), @(6.131935)],\
	  @[@(22.166667), @(113.55)],\
	  @[@(41.997346), @(21.427996)],\
	  @[@(-18.87919), @(47.507905)],\
	  @[@(-13.962612), @(33.774119)],\
	  @[@(3.139003), @(101.686855)],\
	  @[@(4.175496), @(73.509347)],\
	  @[@(12.639232), @(-8.002889)],\
	  @[@(35.898909), @(14.514553)],\
	  @[@(7.116421), @(171.185774)],\
	  @[@(14.616065), @(-61.05878)],\
	  @[@(18.07353), @(-15.958237)],\
	  @[@(-20.166896), @(57.502332)],\
	  @[@(-12.780949), @(45.227872)],\
	  @[@(19.432608), @(-99.133208)],\
	  @[@(6.914712), @(158.161027)],\
	  @[@(47.010453), @(28.86381)],\
	  @[@(43.737411), @(7.420816)],\
	  @[@(47.886399), @(106.905744)],\
	  @[@(42.43042), @(19.259364)],\
	  @[@(16.706523), @(-62.215738)],\
	  @[@(33.97159), @(-6.849813)],\
	  @[@(-25.891968), @(32.605135)],\
	  @[@(19.763306), @(96.07851)],\
	  @[@(39.826385), @(46.763595)],\
	  @[@(-22.560881), @(17.065755)],\
	  @[@(-0.546686), @(166.921091)],\
	  @[@(27.717245), @(85.323961)],\
	  @[@(52.370216), @(4.895168)],\
	  @[@(12.1091242), @(-68.9316546)],\
	  @[@(-22.255823), @(166.450524)],\
	  @[@(-41.28646), @(174.776236)],\
	  @[@(12.114993), @(-86.236174)],\
	  @[@(13.511596), @(2.125385)],\
	  @[@(9.076479), @(7.398574)],\
	  @[@(-19.055371), @(-169.917871)],\
	  @[@(-29.056394), @(167.959588)],\
	  @[@(39.039219), @(125.762524)],\
	  @[@(35.185566), @(33.382276)],\
	  @[@(15.177801), @(145.750967)],\
	  @[@(59.913869), @(10.752245)],\
	  @[@(23.58589), @(58.405923)],\
	  @[@(33.729388), @(73.093146)],\
	  @[@(7.500384), @(134.624289)],\
	  @[@(31.9073509), @(35.5354719)],\
	  @[@(9.101179), @(-79.402864)],\
	  @[@(-9.4438), @(147.180267)],\
	  @[@(-25.26374), @(-57.575926)],\
	  @[@(-12.046374), @(-77.042793)],\
	  @[@(14.599512), @(120.98422)],\
	  @[@(-25.06629), @(-130.100464)],\
	  @[@(52.229676), @(21.012229)],\
	  @[@(38.722252), @(-9.139337)],\
	  @[@(18.466334), @(-66.105722)],\
	  @[@(25.285447), @(51.53104)],\
	  @[@(-20.882057), @(55.450675)],\
	  @[@(44.426767), @(26.102538)],\
	  @[@(55.755826), @(37.6173)],\
	  @[@(-1.957875), @(30.112735)],\
	  @[@(46.775846), @(-56.180636)],\
	  @[@(13.160025), @(-61.224816)],\
	  @[@(-13.850696), @(-171.751355)],\
	  @[@(43.935591), @(12.447281)],\
	  @[@(0.330192), @(6.733343)],\
	  @[@(24.749403), @(46.902838)],\
	  @[@(14.764504), @(-17.366029)],\
	  @[@(44.786568), @(20.448922)],\
	  @[@(-4.619143), @(55.451315)],\
	  @[@(8.465677), @(-13.231722)],\
	  @[@(1.280095), @(103.850949)],\
	  @[@(48.145892), @(17.107137)],\
	  @[@(46.056947), @(14.505751)],\
	  @[@(-9.445638), @(159.9729)],\
	  @[@(2.046934), @(45.318162)],\
	  @[@(-25.747868), @(28.229271)],\
	  @[@(-54.28325), @(-36.493735)],\
	  @[@(37.566535), @(126.977969)],\
	  @[@(42.22146), @(43.964405)],\
	  @[@(4.859363), @(31.57125)],\
	  @[@(40.416775), @(-3.70379)],\
	  @[@(6.89407), @(79.902478)],\
	  @[@(17.896435), @(-62.852201)],\
	  @[@(17.302606), @(-62.717692)],\
	  @[@(14.010109), @(-60.987469)],\
	  @[@(18.067519), @(-63.082466)],\
	  @[@(15.500654), @(32.559899)],\
	  @[@(5.852036), @(-55.203828)],\
	  @[@(78.062), @(22.055)],\
	  @[@(-26.305448), @(31.136672)],\
	  @[@(59.329323), @(18.068581)],\
	  @[@(46.947974), @(7.447447)],\
	  @[@(33.513807), @(36.276528)],\
	  @[@(25.032969), @(121.565418)],\
	  @[@(38.559772), @(68.787038)],\
	  @[@(-6.162959), @(35.751607)],\
	  @[@(13.756331), @(100.501765)],\
	  @[@(-8.556856), @(125.560314)],\
	  @[@(6.172497), @(1.231362)],\
	  @[@(-9.2005), @(-171.848)],\
	  @[@(-21.139342), @(-175.204947)],\
	  @[@(46.848185), @(29.596805)],\
	  @[@(10.654901), @(-61.501926)],\
	  @[@(-37.068042), @(-12.311315)],\
	  @[@(36.806495), @(10.181532)],\
	  @[@(39.933364), @(32.859742)],\
	  @[@(37.960077), @(58.326063)],\
	  @[@(21.467458), @(-71.13891)],\
	  @[@(-8.520066), @(179.198128)],\
	  @[@(18.3419), @(-64.930701)],\
	  @[@(0.347596), @(32.58252)],\
	  @[@(50.4501), @(30.5234)],\
	  @[@(24.299174), @(54.697277)],\
	  @[@(51.507351), @(-0.127758)],\
	  @[@(38.907192), @(-77.036871)],\
	  @[@(-34.901113), @(-56.164531)],\
	  @[@(41.299496), @(69.240073)],\
	  @[@(-17.733251), @(168.327325)],\
	  @[@(41.902179), @(12.453601)],\
	  @[@(10.480594), @(-66.903606)],\
	  @[@(21.027764), @(105.83416)],\
	  @[@(-13.282509), @(-176.176447)],\
	  @[@(27.125287), @(-13.1625)],\
	  @[@(15.369445), @(44.191007)],\
	  @[@(-15.387526), @(28.322817)],\
	  @[@(-17.825166), @(31.03351)]]

#define ENCODED_CLLOCATION_BASE @"<?xml version=\"1.0\" encoding=\"UTF-8\"?>\
<!DOCTYPE plist PUBLIC \"-//Apple//DTD PLIST 1.0//EN\" \"http://www.apple.com/DTDs/PropertyList-1.0.dtd\">\
<plist version=\"1.0\">\
<dict>\
	<key>$archiver</key>\
	<string>NSKeyedArchiver</string>\
	<key>$objects</key>\
	<array>\
		<string>$null</string>\
		<dict>\
			<key>$class</key>\
			<dict>\
				<key>CF$UID</key>\
				<integer>2</integer>\
			</dict>\
			<key>kCLLocationCodingKeyAltitude</key>\
			<real>ALTPLACE</real>\
			<key>kCLLocationCodingKeyCoordinateLatitude</key>\
			<real>LATPLACE</real>\
			<key>kCLLocationCodingKeyCoordinateLongitude</key>\
			<real>LONGPLACE</real>\
			<key>kCLLocationCodingKeyCourse</key>\
			<real>COURSEPLACE</real>\
			<key>kCLLocationCodingKeyHorizontalAccuracy</key>\
			<real>HORZACPLACE</real>\
			<key>kCLLocationCodingKeyLifespan</key>\
			<real>LIFESPAPLACE</real>\
			<key>kCLLocationCodingKeySpeed</key>\
			<real>SPEEDPLACE</real>\
			<key>kCLLocationCodingKeyTimestamp</key>\
			<real>TIMESTAMPPLACE</real>\
			<key>kCLLocationCodingKeyType</key>\
			<integer>TYPEPLACE</integer>\
			<key>kCLLocationCodingKeyVerticalAccuracy</key>\
			<real>VERTACPLACE</real>\
		</dict>\
		<dict>\
			<key>$classes</key>\
			<array>\
				<string>CLLocation</string>\
				<string>NSObject</string>\
			</array>\
			<key>$classname</key>\
			<string>CLLocation</string>\
		</dict>\
	</array>\
	<key>$top</key>\
	<dict>\
		<key>root</key>\
		<dict>\
			<key>CF$UID</key>\
			<integer>1</integer>\
		</dict>\
	</dict>\
	<key>$version</key>\
	<integer>100000</integer>\
</dict>\
</plist>\
"