var s_resource = s_resource || [
	"res/avatar.plist",
	"res/avatar.png",
	"res/bg-minigame-1.png",
	"res/bg_xocdia.png",
	"res/bigsmall_bg.png",
	"res/CaoThap.plist",
	"res/CaoThap.png",
	"res/Card.plist",
	"res/Card.png",
	"res/data/LevelData.json",
	"res/data/VipData.json",
	"res/dialog.plist",
	"res/dialog.png",
	"res/effectMini.plist",
	"res/effectMini.png",
	"res/FloatButton.plist",
	"res/FloatButton.png",
	"res/fonts/bigsmall_number_font.fnt",
	"res/fonts/bigsmall_number_font.png",
	"res/fonts/game-result-font1.fnt",
	"res/fonts/game-result-font1.png",
	"res/fonts/game-result-font2.fnt",
	"res/fonts/game-result-font2.png",
	"res/fonts/minigame-number-1.fnt",
	"res/fonts/minigame-number-1.png",
	"res/fonts/Roboto-BoldCondensed.ttf",
	"res/fonts/Roboto-Condensed.ttf",
	"res/fonts/RobotoBoldCondensed_25.fnt",
	"res/fonts/RobotoBoldCondensed_25.png",
	"res/fonts/RobotoBoldCondensed_30.fnt",
	"res/fonts/RobotoBoldCondensed_30.png",
	"res/fonts/RobotoBoldCondensed_40.fnt",
	"res/fonts/RobotoBoldCondensed_40.png",
	"res/fonts/RobotoCondensed_25.fnt",
	"res/fonts/RobotoCondensed_25.png",
	"res/fonts/RobotoCondensed_30.fnt",
	"res/fonts/RobotoCondensed_30.png",
	"res/fonts/Roboto_BoldCondensed_36_Glow.fnt",
	"res/fonts/Roboto_BoldCondensed_36_Glow.png",
	"res/fonts/UTM-AvoBold.ttf",
	"res/fonts/UTMAvoBold_25.fnt",
	"res/fonts/UTMAvoBold_25.png",
	"res/fonts/UTMAvoBold_30.fnt",
	"res/fonts/UTMAvoBold_30.png",
	"res/fonts/UTMAvoBold_40.fnt",
	"res/fonts/UTMAvoBold_40.png",
	"res/fonts/videoPokerRewardFont.fnt",
	"res/fonts/videoPokerRewardFont.png",
	"res/game-bg.jpg",
	"res/GameList.plist",
	"res/GameList.png",
	"res/gamemini.plist",
	"res/gamemini.png",
	"res/GameScene.plist",
	"res/GameScene.png",
	"res/gold-icon.png",
	"res/gp_table.png",
	"res/HDList.plist",
	"res/hilo_bg.png",
	"res/home.plist",
	"res/home.png",
	"res/lobby.plist",
	"res/lobby.png",
	"res/MiniPoker.plist",
	"res/MiniPoker.png",
	"res/mnpk_bg.png",
	"res/Sound/bellopen.mp3",
	"res/Sound/call2.mp3",
	"res/Sound/chia_bai.mp3",
	"res/Sound/chuyen_view.mp3",
	"res/Sound/danh_bai.mp3",
	"res/Sound/end_vongquay.mp3",
	"res/Sound/join_room.mp3",
	"res/Sound/losing.mp3",
	"res/Sound/lucky_wheel.mp3",
	"res/Sound/multichip.mp3",
	"res/Sound/open_card.mp3",
	"res/Sound/singlechip.mp3",
	"res/Sound/winning.mp3",
	"res/videopoker.plist",
	"res/videopoker.png",
	"res/VongQuay.plist",
	"res/VongQuay.png",
	"res/XocDia.plist",
	"res/XocDia.png"
];

var s_texture = s_texture || [
	{src:"res/CaoThap.png",plist:"res/CaoThap.plist"},
	{src:"res/avatar.png",plist:"res/avatar.plist"},
	{src:"res/Card.png",plist:"res/Card.plist"},
	{src:"res/dialog.png",plist:"res/dialog.plist"},
	{src:"res/effectMini.png",plist:"res/effectMini.plist"},
	{src:"res/FloatButton.png",plist:"res/FloatButton.plist"},
	{src:"res/GameList.png",plist:"res/GameList.plist"},
	{src:"res/gamemini.png",plist:"res/gamemini.plist"},
	{src:"res/GameScene.png",plist:"res/GameScene.plist"},
	{src:"res/home.png",plist:"res/home.plist"},
	{src:"res/lobby.png",plist:"res/lobby.plist"},
	{src:"res/MiniPoker.png",plist:"res/MiniPoker.plist"},
	{src:"res/videopoker.png",plist:"res/videopoker.plist"},
	{src:"res/VongQuay.png",plist:"res/VongQuay.plist"},
	{src:"res/XocDia.png",plist:"res/XocDia.plist"}
];

var s_bitmap_font = s_bitmap_font || [
	{src:"res/fonts/bigsmall_number_font.png",fnt:"res/fonts/bigsmall_number_font.fnt"},
	{src:"res/fonts/game-result-font1.png",fnt:"res/fonts/game-result-font1.fnt"},
	{src:"res/fonts/game-result-font2.png",fnt:"res/fonts/game-result-font2.fnt"},
	{src:"res/fonts/minigame-number-1.png",fnt:"res/fonts/minigame-number-1.fnt"},
	{src:"res/fonts/RobotoBoldCondensed_25.png",fnt:"res/fonts/RobotoBoldCondensed_25.fnt"},
	{src:"res/fonts/RobotoBoldCondensed_30.png",fnt:"res/fonts/RobotoBoldCondensed_30.fnt"},
	{src:"res/fonts/RobotoBoldCondensed_40.png",fnt:"res/fonts/RobotoBoldCondensed_40.fnt"},
	{src:"res/fonts/RobotoCondensed_25.png",fnt:"res/fonts/RobotoCondensed_25.fnt"},
	{src:"res/fonts/RobotoCondensed_30.png",fnt:"res/fonts/RobotoCondensed_30.fnt"},
	{src:"res/fonts/Roboto_BoldCondensed_36_Glow.png",fnt:"res/fonts/Roboto_BoldCondensed_36_Glow.fnt"},
	{src:"res/fonts/UTMAvoBold_25.png",fnt:"res/fonts/UTMAvoBold_25.fnt"},
	{src:"res/fonts/UTMAvoBold_30.png",fnt:"res/fonts/UTMAvoBold_30.fnt"},
	{src:"res/fonts/UTMAvoBold_40.png",fnt:"res/fonts/UTMAvoBold_40.fnt"},
	{src:"res/fonts/videoPokerRewardFont.png",fnt:"res/fonts/videoPokerRewardFont.fnt"},
];

var s_sound = s_sound || [
	"res/Sound/bellopen.mp3",
	"res/Sound/call2.mp3",
	"res/Sound/chia_bai.mp3",
	"res/Sound/chuyen_view.mp3",
	"res/Sound/danh_bai.mp3",
	"res/Sound/end_vongquay.mp3",
	"res/Sound/join_room.mp3",
	"res/Sound/losing.mp3",
	"res/Sound/lucky_wheel.mp3",
	"res/Sound/multichip.mp3",
	"res/Sound/open_card.mp3",
	"res/Sound/singlechip.mp3",
	"res/Sound/winning.mp3"
];
