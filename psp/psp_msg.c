#include "psp.h"

extern int os9x_language;

char *s9xTYL_lang[LANGUAGE_NUMBER]={
	"english"
};

#define MSG_TOTAL_ENTRIES 143
typedef struct {
	int msg_id;
	char *msg;
	int len;  // MSG_DEFAULT : to use default
						// >=0 : wait for len frames, 
					  //  -1 : wait for a confirmation before closing dialog
					  //  -2 : yes/no dialog
} t_err_entry;

t_err_entry s9xTYL_msg_en[MSG_TOTAL_ENTRIES]= {
//english
		//error
		{ERR_OUT_OF_MEM,"Out of memory",60},
		{ERR_READ_MEMSTICK,"Error reading memstick.\nPlease verify it (using a PC card reader), it may be corrupted.",60},
		//confirm
  	{ASK_EXIT,"Exit Snes9XTYL ?",-2},
  	{ASK_DELETE,"Delete file ?",-2},
  	//info
  	{INFO_USB_ON,"USB activated",30},
  	{INFO_USB_OFF,"USB disabled",30},
  	{INFO_DELETING,"Deleting...",0},
  	{INFO_EXITING,"Exiting, please wait...",0},
  	//filer
  	{FILER_STATUS_CANEXIT1,SJIS_CIRCLE " RUN " SJIS_SQUARE " RUN default settings  " SJIS_STAR "  " SJIS_CROSS " TO GAME  "  SJIS_STAR "  " SJIS_TRIANGLE " Par. dir.  "  SJIS_STAR "  " SJIS_UP "," SJIS_DOWN "," SJIS_LEFT "," SJIS_RIGHT ", to browse",0},
  	{FILER_STATUS_NOEXIT1,SJIS_CIRCLE " RUN " SJIS_SQUARE " RUN default settings  "  SJIS_STAR "  " SJIS_TRIANGLE " Parent dir.          " SJIS_UP "," SJIS_DOWN "," SJIS_LEFT "," SJIS_RIGHT ", to browse list",0},
  	{FILER_STATUS_CANEXIT2,SJIS_CIRCLE " RUN " SJIS_CROSS "BACK TO GAME " SJIS_TRIANGLE " Parent dir.  " SJIS_UP "," SJIS_DOWN "," SJIS_LEFT "," SJIS_RIGHT ", to browse list",0},
  	{FILER_STATUS_NOEXIT2,SJIS_CIRCLE " RUN " SJIS_TRIANGLE " Parent dir.                  " SJIS_UP "," SJIS_DOWN "," SJIS_LEFT "," SJIS_RIGHT ", to browse list",0},
  	
  	{FILER_HELP_WINDOW1,"Press START to switch between",0},
  	{FILER_HELP_WINDOW2,"NORMAL and NETPLAY mode.",0},
#ifdef FW3X
  	{FILER_HELP_WINDOW3," ",0},
#ifdef HOME_HOOK
  	{FILER_HELP_WINDOW4,"Press HOME to exit.",0},
#else
    {FILER_HELP_WINDOW4,"Press L+R to exit.",0},
#endif
#else
#ifdef HOME_HOOK
    {FILER_HELP_WINDOW3,"Press HOME to exit.",0},
#else
    {FILER_HELP_WINDOW3,"Press L+R to exit.",0},
#endif
  	{FILER_HELP_WINDOW4,"Press R to switch USB on/off.",0},
#endif


  	{FILER_HELP_WINDOW5,"Press SELECT to delete file.",0},
  	
  	{FILE_IPS_PATCHSUCCESS,"IPS Patch applied successfully",0},
  	
  	{MENU_STATUS_GENERIC_MSG1,"Press " SJIS_CROSS " to return",0},
  	{MENU_STATUS_GENERIC_NEEDRELOAD,"Changes may require a RELOAD to take effect",0},
  	{MENU_STATUS_GENERIC_NEEDRESET,"Changes may require a RESET to take effect",0},
  	
  	{MENU_SOUND_MODE_NOTEMUL,"not emulated",0},
		{MENU_SOUND_MODE_EMULOFF,"emulated, no output",0},
  	{MENU_SOUND_MODE_EMULON,"emulated, output",0},  	
  	
  	{MENU_STATE_CHOOSEDEL,"Choose a slot to DELETE",0},
  	{MENU_STATE_CHOOSELOAD,"Choose a slot to LOAD",0},
  	{MENU_STATE_CHOOSESAVE,"Choose a slot to SAVE",0},
  	{MENU_STATE_FREESLOT,"FREE",0},  	
  	{MENU_STATE_SCANNING,"Scanning used slots...",0},  	
  	
  	  	
  	{ERR_INIT_OSK,"cannot init OSK",0},
  	{ERR_ADD_CODE,"Cannot add cheat code, too many already enterred!",0},
  	
  	{MENU_CHEATS_ENTERGF,"Enter a GoldFinger code",0},
  	{MENU_CHEATS_ENTERPAR,"Enter a Pro Action Replay code",0},
  	{MENU_CHEATS_ENTERGG,"Enter a Game Genie code",0},
  	{MENU_CHEATS_ENTERRAW,"Enter a RAW code\nFormat is ADDRESS - NEW VALUE",0},  	  	
  	
  	{MENU_STATE_CONFIRMLOAD,"Current game progress will be lost.\nContinue ?",0},
		{MENU_STATE_CONFIRMDELETE,"Delete current state ?",0},
		{MENU_STATE_CONFIRMSAVE,"Overwrite current savestate ?",0},
		{MENU_STATE_ISSAVING,"Saving state...",0},
		{MENU_STATE_ISLOADING,"Loading state...",0},
		{MENU_STATE_ISIMPORTING,"Importing state...",0},
		{MENU_STATE_ISEXPORTINGS9X,"Exporting SNES9X state...",0},		
		{MENU_STATE_NOSTATE,"No state available...",0},
		{MENU_GAME_SAVINGDEFAULTSETTINGS,"Saving current settings as default profile",0},
		{MENU_GAME_CONFIRMRESET,"Reset Snes ?",0},
		{MENU_MISC_SAVINGJPEG,"Saving JPEG snapshot...",0},
  	
  	
  	// GAME
  	{MENU_ICONS_GAME,"GAME",0},
  	{MENU_ICONS_GAME_RESET,"Reset SNES",0},  	
  	{MENU_ICONS_GAME_NEW,"Load new game",0},
		{MENU_ICONS_GAME_DEFAULTSETTINGS,"Make Settings DEFAULT",0},
		{MENU_ICONS_GAME_DEFAULTSETTINGS_HELP,"Make current settings the default\nfor all roms when no specific\none exists",0},		
		{MENU_ICONS_GAME_EXIT,"Exit Snes9xTYL",0},
		// LOAD/SAVE
		{MENU_ICONS_LOADSAVE,"LOAD/SAVE",0},
		{MENU_ICONS_LOADSAVE_LOADSTATE,"Load state",0},
		{MENU_ICONS_LOADSAVE_LOADSTATE_HELP,"Load a previously saved state.\nSavestate is like a snapshot\nof the snes state, everything\nis saved.",0},		
		{MENU_ICONS_LOADSAVE_SAVESTATE,"Save state",0},
		{MENU_ICONS_LOADSAVE_SAVESTATE_HELP,"Save state",0},		
		{MENU_ICONS_LOADSAVE_DELETESTATE,"Delete state",0},
		{MENU_ICONS_LOADSAVE_DELETESTATE_HELP,"Delete state",0},		
		{MENU_ICONS_LOADSAVE_IMPORTSTATE,"Import state",0},
		{MENU_ICONS_LOADSAVE_IMPORTSTATE_HELP,"Import a state from a previous\nversion or from uosnes9x.",0},		
		
		{MENU_ICONS_LOADSAVE_EXPORTS9XSTATE,"Export SNES9X state",0},
		{MENU_ICONS_LOADSAVE_EXPORTS9XSTATE_HELP,"Export a state using SNES9X format.",0},		
		
		{MENU_ICONS_LOADSAVE_AUTOSAVETIMER,"Autosavestate timer",0},
		{MENU_ICONS_LOADSAVE_AUTOSAVETIMER_HELP,"Allows to have an auto\nsavestate performed regularly.",0},		
		{MENU_ICONS_LOADSAVE_AUTOSRAM,"Autosave updated SRAM",0},
		{MENU_ICONS_LOADSAVE_AUTOSRAM_HELP,"Allows to have SRAM saved\nafter each change.",0},		
		// CONTROLS	
		{MENU_ICONS_CONTROLS,"CONTROLS",0},		
		{MENU_ICONS_CONTROLS_REDEFINE,"Redefine",0},
		{MENU_ICONS_CONTROLS_REDEFINE_HELP,"Redefine buttons mapping.",0},		
		{MENU_ICONS_CONTROLS_INPUT,"Emulated input",0},	
		{MENU_ICONS_CONTROLS_INPUT_HELP,"Choose current active\nsnes controller.",0},			
		// VIDEO OPTIONS
		{MENU_ICONS_VIDEO,"VIDEO",0},
		{MENU_ICONS_VIDEO_MODE,"Video mode",0},
		{MENU_ICONS_VIDEO_MODE_HELP,"Change the aspect ratio\n4:3 is adviced",0},		
		{MENU_ICONS_VIDEO_ENGINE,"Engine",0},	
		{MENU_ICONS_VIDEO_ENGINE_HELP,"Hardware accelerated mode\nis not always the fastest",0},			
		{MENU_ICONS_VIDEO_SLIMITONOFF,"Speed limit switch",0},
		{MENU_ICONS_VIDEO_SLIMITONOFF_HELP,"Turn on to limit the speed\nof the game.",0},		
		{MENU_ICONS_VIDEO_SLIMITVALUE,"Speed limit fps",0},
		{MENU_ICONS_VIDEO_SLIMITVALUE_HELP,"Only used if speed limit\nhas been turned on.",0},		
		{MENU_ICONS_VIDEO_FSKIP,"Frameskip",0},
		{MENU_ICONS_VIDEO_FSKIP_HELP,"Choose a fixed value if you\nhave some sprites\ndisappearing.",0},		
		{MENU_ICONS_VIDEO_SMOOTHING,"Smoothing",0},		
		{MENU_ICONS_VIDEO_SMOOTHING_HELP,"Should be on since it costs\nnothing.",0},				
		{MENU_ICONS_VIDEO_VSYNC,"VSync",0},
		{MENU_ICONS_VIDEO_VSYNC_HELP,"This costs lots of fps\nand should be turned off.",0},		
		{MENU_ICONS_VIDEO_PALASNTSC,"Render PAL as NTSC",0},
		{MENU_ICONS_VIDEO_PALASNTSC_HELP,"Force PAL games to be emulated\nlike NTSC ones : 224 lines\ninstead of 240.",0},		
		{MENU_ICONS_VIDEO_GAMMA,"Gamma correction",0},
		{MENU_ICONS_VIDEO_GAMMA_HELP,"Allows brighter rendering",0},		
		{MENU_ICONS_VIDEO_SCRCALIB,"Screen calibration",0},	
		{MENU_ICONS_VIDEO_SCRCALIB_HELP,"Help to get rid of the nasty\nblack borders.",0},			
		{MENU_ICONS_VIDEO_SHOWFPS,"Show FPS",0},
		{MENU_ICONS_VIDEO_SHOWFPS_HELP,"First line is emulated frames\nSecond one is real fps.",0},		
		// SOUND OPTIONS
		{MENU_ICONS_SOUND,"SOUND",0},
		{MENU_ICONS_SOUND_MODE,"Sound mode",0},
		{MENU_ICONS_SOUND_MODE_HELP,"not emulated is the fastest\nbut some games won't run.",0},		
		{MENU_ICONS_SOUND_FREQ,"Output frequency",0},
		{MENU_ICONS_SOUND_FREQ_HELP,"The lower the faster\nThe higher the best sound quality",0},		
		{MENU_ICONS_SOUND_APURATIO,"APU Cycles ratio",0},	
		{MENU_ICONS_SOUND_APURATIO_HELP,"For advanced users knowing\nwhat they do.",0},			
		// MISC OPTIONS
		{MENU_ICONS_MISC,"MISC",0},	
		{MENU_ICONS_MISC_FILEVIEWER,"View file",0},	
		{MENU_ICONS_MISC_FILEVIEWER_HELP,"Minimalist file viewer",0},			
		{MENU_ICONS_MISC_PSPCLOCK,"PSP Clockspeed",0},	
		{MENU_ICONS_MISC_PSPCLOCK_HELP,"value>222Mhz is NOT overclocking\nit's safe but battery runs out\nfaster",0},			
		{MENU_ICONS_MISC_HACKDEBUG,"Hack/debug menu",0},
		{MENU_ICONS_MISC_HACKDEBUG_HELP,"For advanced users.\nHelp to tune the rendering and\ngain some speed.",0},		
		{MENU_ICONS_MISC_SNAPSHOT,"Snapshot",0},
		{MENU_ICONS_MISC_SNAPSHOT_HELP,"Take a snapshot of the current\ngame screen.\nUsed in file browser.",0},		
		{MENU_ICONS_MISC_RANDBG,"Randomize BG",0},
		{MENU_ICONS_MISC_RANDBG_HELP,"Randomize BG from the DATA/logo.zip\nfile.",0},		
		{MENU_ICONS_MISC_BGMUSIC,"Menu background music",0},
		{MENU_ICONS_MISC_BGMUSIC_HELP,"Menu background music requires\nmake PSP running at 300Mhz\nMusic are from DATA/music.zip file.\nSPC format only.",0},		
		{MENU_ICONS_MISC_BGFX,"Menu background fx",0},	
		{MENU_ICONS_MISC_BGFX_HELP,"Nice FX from PS2DEV spline sample.",0},			
		{MENU_ICONS_MISC_PADBEEP,"Pad beep",0},	
		{MENU_ICONS_MISC_PADBEEP_HELP,"The beep sounds when browsing\nmenu and files.",0},			
		// CHEATS
		{MENU_ICONS_CHEATS,"CHEATS",0},
		{MENU_ICONS_CHEATS_ADDRAW,"Add a RAW code",0},
		{MENU_ICONS_CHEATS_ADDRAW_HELP,"Add a RAW code",0},		
		{MENU_ICONS_CHEATS_ADDGG,"Add a Game Genie code",0},
		{MENU_ICONS_CHEATS_ADDGG_HELP,"Add a Game Genie code",0},		
		{MENU_ICONS_CHEATS_ADDPAR,"Add a Pro Action Replay code",0},
		{MENU_ICONS_CHEATS_ADDPAR_HELP,"Add a Pro Action Replay code",0},		
		{MENU_ICONS_CHEATS_ADDGF,"Add a GoldFinger code",0},
		{MENU_ICONS_CHEATS_ADDGF_HELP,"Add a GoldFinger code",0},		
		{MENU_ICONS_CHEATS_DISABLE,"Disable code",0},
		{MENU_ICONS_CHEATS_DISABLE_HELP,"Disable code",0},		
		{MENU_ICONS_CHEATS_DISABLEALL,"Disable all codes",0},
		{MENU_ICONS_CHEATS_DISABLEALL_HELP,"Disable all codes",0},		
		{MENU_ICONS_CHEATS_ENABLE,"Enable code",0},
		{MENU_ICONS_CHEATS_ENABLE_HELP,"Enable code",0},		
		{MENU_ICONS_CHEATS_ENABLEALL,"Enable all codes",0},
		{MENU_ICONS_CHEATS_ENABLEALL_HELP,"Enable all codes",0},		
		{MENU_ICONS_CHEATS_REMOVE,"Remove code",0},
		{MENU_ICONS_CHEATS_REMOVE_HELP,"Remove code",0},		
		{MENU_ICONS_CHEATS_REMOVEALL,"Remove all codes",0},
		{MENU_ICONS_CHEATS_REMOVEALL_HELP,"Remove all codes",0},		
		// ABOUT
		{MENU_ICONS_ABOUT,"ABOUT",0},
		{MENU_ICONS_ABOUT_CREDITS,"Credits",0},
		{MENU_ICONS_ABOUT_VERSION,"Version infos",0},
};

t_err_entry s9xTYL_msg_ja[MSG_TOTAL_ENTRIES]= {
//japanese
		//error
		{ERR_OUT_OF_MEM,"�������O�ł��B",60},
		{ERR_READ_MEMSTICK,"�������[�X�e�B�b�N�̓ǂݍ��݂ŃG���[���������܂����B\n�������[�X�e�B�b�N���m�F���Ă��������B\n(PC�̃J�[�h���[�_�[���g���Ă�������)\n�������[�X�e�B�b�N���j�����Ă���\��������܂��B",60},
		//confirm
  	{ASK_EXIT,"Snes9XTYL���I�����܂���?",-2},
  	{ASK_DELETE,"�t�@�C�����폜���܂���?",-2},
  	//info
  	{INFO_USB_ON,"USB���L��������܂���",30},
  	{INFO_USB_OFF,"USB������������܂���",30},
  	{INFO_DELETING,"�폜���Ă��܂�...",0},
  	{INFO_EXITING,"�I�����Ă��܂��B���΂炭���҂���������...",0},
  	//filer
  	{FILER_STATUS_CANEXIT1,SJIS_CIRCLE " ���s " SJIS_SQUARE " �W���ݒ�Ŏ��s  " SJIS_STAR "  " SJIS_CROSS " �Q�[���ɖ߂�  "  SJIS_STAR "  " SJIS_TRIANGLE " ���  "  SJIS_STAR "  " SJIS_UP "," SJIS_DOWN "," SJIS_LEFT "," SJIS_RIGHT " �ړ�",0},
  	{FILER_STATUS_NOEXIT1,SJIS_CIRCLE " ���s " SJIS_SQUARE " �W���ݒ�Ŏ��s  "  SJIS_STAR "  " SJIS_TRIANGLE " ���          " SJIS_UP "," SJIS_DOWN "," SJIS_LEFT "," SJIS_RIGHT " ���X�g���ړ�",0},
  	{FILER_STATUS_CANEXIT2,SJIS_CIRCLE " ���s " SJIS_CROSS "�Q�[���ɖ߂� " SJIS_TRIANGLE " ���  " SJIS_UP "," SJIS_DOWN "," SJIS_LEFT "," SJIS_RIGHT " ���X�g���ړ�",0},
  	{FILER_STATUS_NOEXIT2,SJIS_CIRCLE " ���s " SJIS_TRIANGLE " ���                  " SJIS_UP "," SJIS_DOWN "," SJIS_LEFT "," SJIS_RIGHT " ���X�g���ړ�",0},
  	
  	{FILER_HELP_WINDOW1,"�W���ƒʐM�ΐ탂�[�h��؂�ւ���",0},
  	{FILER_HELP_WINDOW2,"�ɂ�START�������Ă�������",0},
#ifdef FW3X
  	{FILER_HELP_WINDOW3," ",0},
#ifdef HOME_HOOK
  	{FILER_HELP_WINDOW4,"�I������ɂ�HOME�������Ă�������",0},
#else
    {FILER_HELP_WINDOW4,"�I������ɂ�L+R�������Ă�������",0},
#endif
#else
#ifdef HOME_HOOK
    {FILER_HELP_WINDOW3,"�I������ɂ�HOME�������Ă�������",0},
#else
    {FILER_HELP_WINDOW3,"�I������ɂ�L+R�������Ă�������",0},
#endif
  	{FILER_HELP_WINDOW4,"USB�ݵ̐؂�ւ���R�������Ă�������",0},
#endif


  	{FILER_HELP_WINDOW5,"�폜����ɂ�SELECT�������Ă�������",0},
  	
  	{FILE_IPS_PATCHSUCCESS,"IPS�p�b�`�̓K�p�ɐ������܂���",0},
  	
  	{MENU_STATUS_GENERIC_MSG1,"�߂�ɂ�" SJIS_CROSS "�������Ă�������",0},
  	{MENU_STATUS_GENERIC_NEEDRELOAD,"�ύX��K�p����ɂ͍ēǂݍ��݂��K�v��������܂���",0},
  	{MENU_STATUS_GENERIC_NEEDRESET,"�ύX��K�p����ɂ̓��Z�b�g���K�v��������܂���",0},
  	
  	{MENU_SOUND_MODE_NOTEMUL,"�G�~�����[�g���Ȃ�",0},
	{MENU_SOUND_MODE_EMULOFF,"�G�~�����[�g���邪�o�͂��Ȃ�",0},
  	{MENU_SOUND_MODE_EMULON,"�G�~�����[�g���A�o�͂���",0},
  	
  	{MENU_STATE_CHOOSEDEL,"�폜����X���b�g��I��ł�������",0},
  	{MENU_STATE_CHOOSELOAD,"�ǂݍ��ރX���b�g��I��ł�������",0},
  	{MENU_STATE_CHOOSESAVE,"�ۑ�����X���b�g��I��ł�������",0},
  	{MENU_STATE_FREESLOT,"��",0},
  	{MENU_STATE_SCANNING,"�g�p�ς݃X���b�g�𒲂ׂĂ��܂�...",0},
  	
  	  	
  	{ERR_INIT_OSK,"OSK���������ł��܂���",0},
  	{ERR_ADD_CODE,"�`�[�g�R�[�h��ǉ��ł��܂���B���ɓ��͂���Ă���R�[�h���������܂��B",0},
  	
  	{MENU_CHEATS_ENTERGF,"GoldFinger�R�[�h����͂��Ă�������",0},
  	{MENU_CHEATS_ENTERPAR,"�v���A�N�V�������v���C�R�[�h����͂��Ă�������",0},
  	{MENU_CHEATS_ENTERGG,"Game Genie�R�[�h����͂��Ă�������",0},
  	{MENU_CHEATS_ENTERRAW,"RAW�R�[�h����͂��Ă�������\n���� : �A�h���X - �V�����l",0},
  
  	{MENU_STATE_CONFIRMLOAD,"���݂̃Q�[���i�s�������܂��B\n���s���܂���?",0},
		{MENU_STATE_CONFIRMDELETE,"���̃X�e�[�g�Z�[�u���폜���܂���?",0},
		{MENU_STATE_CONFIRMSAVE,"���̃X�e�[�g�Z�[�u�ɏ㏑�����܂���?",0},
		{MENU_STATE_ISSAVING,"�X�e�[�g�Z�[�u���Ă��܂�...",0},
		{MENU_STATE_ISLOADING,"��Ԃ�ǂݍ���ł��܂�...",0},
		{MENU_STATE_ISIMPORTING,"�X�e�[�g�Z�[�u���C���|�[�g���Ă��܂�...",0},
		{MENU_STATE_ISEXPORTINGS9X,"SNES9X�X�e�[�g�Z�[�u���G�N�X�|�[�g���Ă��܂�...",0},
		{MENU_STATE_NOSTATE,"�g�p�\�ȃX�e�[�g�Z�[�u������܂���",0},
		{MENU_GAME_SAVINGDEFAULTSETTINGS,"���݂̐ݒ��W���ݒ�Ƃ��ĕۑ����Ă��܂�",0},
		{MENU_GAME_CONFIRMRESET,"Snes�����Z�b�g���܂���?",0},
		{MENU_MISC_SAVINGJPEG,"JPEG�X�i�b�v�V���b�g��ۑ����Ă��܂�...",0},
  	
  	
  	// GAME
  	{MENU_ICONS_GAME,"�Q�[��",0},
  	{MENU_ICONS_GAME_RESET,"SNES�����Z�b�g����",0},
  	{MENU_ICONS_GAME_NEW,"�V�����Q�[����ǂݍ���",0},
		{MENU_ICONS_GAME_DEFAULTSETTINGS,"�W���ݒ���쐬����",0},
		{MENU_ICONS_GAME_DEFAULTSETTINGS_HELP,"���݂̐ݒ����ʂɐݒ�t�@�C�����Ȃ�\n�S�Ă�ROM�Ɏg����W���ݒ�Ƃ���\n�ۑ����܂��B",0},
		{MENU_ICONS_GAME_EXIT,"Snes9xTYL���I������",0},
		// LOAD/SAVE
		{MENU_ICONS_LOADSAVE,"���[�h/�Z�[�u",0},
		{MENU_ICONS_LOADSAVE_LOADSTATE,"�X�e�[�g���[�h",0},
		{MENU_ICONS_LOADSAVE_LOADSTATE_HELP,"�ȑO�ۑ������X�e�[�g�Z�[�u��\n�ǂݍ��݂܂��B�X�e�[�g�Z�[�u��Snes\n�̏�Ԃ̃X�i�b�v�V���b�g�̂悤��\n���̂ŁA���ׂĕۑ�����܂��B",0},
		{MENU_ICONS_LOADSAVE_SAVESTATE,"�X�e�[�g�Z�[�u",0},
		{MENU_ICONS_LOADSAVE_SAVESTATE_HELP,"�X�e�[�g�Z�[�u���܂��B",0},
		{MENU_ICONS_LOADSAVE_DELETESTATE,"�X�e�[�g�Z�[�u���폜",0},
		{MENU_ICONS_LOADSAVE_DELETESTATE_HELP,"�X�e�[�g�Z�[�u�̃Z�[�u�f�[�^��\n�폜���܂��B",0},	
		{MENU_ICONS_LOADSAVE_IMPORTSTATE,"�X�e�[�g�Z�[�u���C���|�[�g",0},
		{MENU_ICONS_LOADSAVE_IMPORTSTATE_HELP,"uosnes9x��ȑO�̃o�[�W��������\n�X�e�[�g�Z�[�u�̃Z�[�u�f�[�^��\n�C���|�[�g���܂��B",0},

		{MENU_ICONS_LOADSAVE_EXPORTS9XSTATE,"SNES9X�̃X�e�[�g�Z�[�u�ɃG�N�X�|�[�g",0},
		{MENU_ICONS_LOADSAVE_EXPORTS9XSTATE_HELP,"SNES9X�t�H�[�}�b�g���g����\n�X�e�[�g�Z�[�u�̃Z�[�u�f�[�^��\n�G�N�X�|�[�g���܂��B",0},	

		{MENU_ICONS_LOADSAVE_AUTOSAVETIMER,"�I�[�g�X�e�[�g�Z�[�u�^�C�}�[",0},
		{MENU_ICONS_LOADSAVE_AUTOSAVETIMER_HELP,"����I�ɃI�[�g�X�e�[�g�Z�[�u��\n�����܂��B",0},
		{MENU_ICONS_LOADSAVE_AUTOSRAM,"SRAM���X�V���ꂽ�Ƃ��ɃI�[�g�Z�[�u����",0},
		{MENU_ICONS_LOADSAVE_AUTOSRAM_HELP,"�ύX���s���邽�т�SRAM��\n�ۑ������悤�ɂ��܂��B",0},
		// CONTROLS
		{MENU_ICONS_CONTROLS,"�R���g���[��",0},
		{MENU_ICONS_CONTROLS_REDEFINE,"�Đݒ�",0},
		{MENU_ICONS_CONTROLS_REDEFINE_HELP,"�{�^�����蓖�Ă��Đݒ肵�܂��B",0},		
		{MENU_ICONS_CONTROLS_INPUT,"�G�~�����[�g�����R���g���[��",0},	
		{MENU_ICONS_CONTROLS_INPUT_HELP,"���ݗL���ɂ���Snes�R���g���[����\n�I��ł��������B",0},			
		// VIDEO OPTIONS
		{MENU_ICONS_VIDEO,"�r�f�I",0},
		{MENU_ICONS_VIDEO_MODE,"�o�̓��[�h",0},
		{MENU_ICONS_VIDEO_MODE_HELP,"�A�X�y�N�g���ύX���܂��B\n4:3�����E����܂��B",0},
		{MENU_ICONS_VIDEO_ENGINE,"�G���W��",0},
		{MENU_ICONS_VIDEO_ENGINE_HELP,"�n�[�h�E�F�A�N�Z�����[�g���[�h��\n�����ő��Ȃ킯�ł͂���܂���B",0},
		{MENU_ICONS_VIDEO_SLIMITONOFF,"���x�����؂�ւ�",0},
		{MENU_ICONS_VIDEO_SLIMITONOFF_HELP,"�Q�[���̑��x�𐧌�����ɂ�\n�I���ɂ��Ă��������B",0},
		{MENU_ICONS_VIDEO_SLIMITVALUE,"FPS���x����",0},
		{MENU_ICONS_VIDEO_SLIMITVALUE_HELP,"���x�������I���̂Ƃ��̂�\n�g���܂��B",0},
		{MENU_ICONS_VIDEO_FSKIP,"�t���[���X�L�b�v",0},
		{MENU_ICONS_VIDEO_FSKIP_HELP,"�\\������Ȃ��X�v���C�g������ꍇ��\n�Œ�l��I��ł��������B",0},
		{MENU_ICONS_VIDEO_SMOOTHING,"�X���[�V���O",0},
		{MENU_ICONS_VIDEO_SMOOTHING_HELP,"�����]���ɂ��Ȃ��Ƃ��̂�\n�I���ɂ��ׂ��ł��B",0},
		{MENU_ICONS_VIDEO_VSYNC,"��������",0},
		{MENU_ICONS_VIDEO_VSYNC_HELP,"����͑�����FPS���]���ɂ���̂�\n�I�t�ɂ��ׂ��ł��B",0},
		{MENU_ICONS_VIDEO_PALASNTSC,"PAL��NTSC�Ƃ��ĕ`�悷��",0},
		{MENU_ICONS_VIDEO_PALASNTSC_HELP,"PAL�̃Q�[����240�{�̐����𑜓x��\n�����224�{�ɂ���NTSC�̂��̂悤��\n�G�~�����[�g����悤�������܂��B",0},		
		{MENU_ICONS_VIDEO_GAMMA,"�K���}�␳",0},
		{MENU_ICONS_VIDEO_GAMMA_HELP,"��薾��߂ȕ`��������܂��B",0},		
		{MENU_ICONS_VIDEO_SCRCALIB,"��ʈʒu�␳",0},
		{MENU_ICONS_VIDEO_SCRCALIB_HELP,"�ז��ȍ����g����菜���̂�\n�𗧂��܂��B",0},			
		{MENU_ICONS_VIDEO_SHOWFPS,"FPS�\\��",0},
		{MENU_ICONS_VIDEO_SHOWFPS_HELP,"1�s�ڂ̓G�~�����[�g�����\n�t���[������\\�����܂��B\n��s�ڂ͖{����FPS��\\�����܂��B",0},
		// SOUND OPTIONS
		{MENU_ICONS_SOUND,"����",0},
		{MENU_ICONS_SOUND_MODE,"�T�E���h���[�h",0},
		{MENU_ICONS_SOUND_MODE_HELP,"�G�~�����[�g���Ȃ��̂��ő��ł���\n�������̃Q�[���͓��삵�܂���B",0},
		{MENU_ICONS_SOUND_FREQ,"�o�͎��g��",0},
		{MENU_ICONS_SOUND_FREQ_HELP,"�Ⴂ�ق��������Ȃ�܂��B\n�����ق����������悭�Ȃ�܂��B",0},
		{MENU_ICONS_SOUND_APURATIO,"APU������",0},
		{MENU_ICONS_SOUND_APURATIO_HELP,"���ꂪ�������邩�m���Ă���\n���x�ȃ��[�U�[�����ł��B",0},
		// MISC OPTIONS
		{MENU_ICONS_MISC,"���̑�",0},
		{MENU_ICONS_MISC_FILEVIEWER,"�t�@�C���\\��",0},
		{MENU_ICONS_MISC_FILEVIEWER_HELP,"�ȒP�ȃt�@�C���r���[���[�ł��B",0},
		{MENU_ICONS_MISC_PSPCLOCK,"PSP�N���b�N���x",0},	
		{MENU_ICONS_MISC_PSPCLOCK_HELP,"222MHz�ȏ�̓I�[�o�[�N���b�N�ł�\n����܂���B\n���S�ł����d�r�𑬂�����܂��B",0},
		{MENU_ICONS_MISC_HACKDEBUG,"Hack�n�b�N/�f�o�b�O���j���[",0},
		{MENU_ICONS_MISC_HACKDEBUG_HELP,"���x�ȃ��[�U�[�����ł��B\n�`��𒲐����ăX�s�[�h��\n����̂ɖ𗧂��܂��B",0},
		{MENU_ICONS_MISC_SNAPSHOT,"�X�i�b�v�V���b�g",0},
		{MENU_ICONS_MISC_SNAPSHOT_HELP,"���݂̃Q�[���̉�ʂ�\n�X�i�b�v�V���b�g���B��܂��B\n�t�@�C���ꗗ�Ŏg���܂��B",0},
		{MENU_ICONS_MISC_RANDBG,"�����_���o�b�N�O���E���h",0},
		{MENU_ICONS_MISC_RANDBG_HELP,"DATA/logo.zip����\n�����_���ɔw�i��\\�����܂��B",0},
		{MENU_ICONS_MISC_BGMUSIC,"���j���[BGM",0},
		{MENU_ICONS_MISC_BGMUSIC_HELP,"���j���[BGM��PSP��300MHz��\n���삳����K�v������܂��B\n���y��DATA/music.zip����Đ����܂��B\nSPC�t�H�[�}�b�g�݂̂ł��B",0},
		{MENU_ICONS_MISC_BGFX,"���j���[�o�b�N�O���E���hCG",0},
		{MENU_ICONS_MISC_BGFX_HELP,"PS2DEV spline sample�̑f�G��CG�ł��B",0},
		{MENU_ICONS_MISC_PADBEEP,"�p�b�h�r�[�v",0},
		{MENU_ICONS_MISC_PADBEEP_HELP,"�r�[�v�������j���[��t�@�C���ꗗ��\n�ړ����Ă���Ƃ��ɖ�܂��B",0},
		// CHEATS
		{MENU_ICONS_CHEATS,"�`�[�g",0},
		{MENU_ICONS_CHEATS_ADDRAW,"RAW�R�[�h�ǉ�",0},
		{MENU_ICONS_CHEATS_ADDRAW_HELP,"RAW�R�[�h��ǉ����܂��B",0},	
		{MENU_ICONS_CHEATS_ADDGG,"Game Genie�R�[�h�ǉ�",0},
		{MENU_ICONS_CHEATS_ADDGG_HELP,"Game Genie�R�[�h��ǉ����܂��B",0},
		{MENU_ICONS_CHEATS_ADDPAR,"�v���A�N�V�������v���C�R�[�h�ǉ�",0},
		{MENU_ICONS_CHEATS_ADDPAR_HELP,"�v���A�N�V�������v���C�R�[�h��\n�ǉ����܂��B",0},
		{MENU_ICONS_CHEATS_ADDGF,"GoldFinger�R�[�h�ǉ�",0},
		{MENU_ICONS_CHEATS_ADDGF_HELP,"GoldFinger�R�[�h��ǉ����܂��B",0},
		{MENU_ICONS_CHEATS_DISABLE,"�R�[�h������",0},
		{MENU_ICONS_CHEATS_DISABLE_HELP,"�R�[�h�𖳌������܂��B",0},		
		{MENU_ICONS_CHEATS_DISABLEALL,"�S�R�[�h������",0},
		{MENU_ICONS_CHEATS_DISABLEALL_HELP,"�S�ẴR�[�h�𖳌������܂��B",0},		
		{MENU_ICONS_CHEATS_ENABLE,"�R�[�h�L����",0},
		{MENU_ICONS_CHEATS_ENABLE_HELP,"�R�[�h��L���ɂ��܂��B",0},		
		{MENU_ICONS_CHEATS_ENABLEALL,"�S�R�[�h�L����",0},
		{MENU_ICONS_CHEATS_ENABLEALL_HELP,"�S�ẴR�[�h��L�������܂��B",0},		
		{MENU_ICONS_CHEATS_REMOVE,"�R�[�h�폜",0},
		{MENU_ICONS_CHEATS_REMOVE_HELP,"�R�[�h���폜���܂��B",0},		
		{MENU_ICONS_CHEATS_REMOVEALL,"�S�R�[�h�폜",0},
		{MENU_ICONS_CHEATS_REMOVEALL_HELP,"�S�ẴR�[�h���폜���܂��B",0},		
		// ABOUT
		{MENU_ICONS_ABOUT,"���̃\\�t�g�ɂ���",0},
		{MENU_ICONS_ABOUT_CREDITS,"�N���W�b�g",0},
		{MENU_ICONS_ABOUT_VERSION,"�o�[�W�������",0},
};

////////////////////////////////////////////////////////////////////////////////////////
// psp_msg_string
// -------------- 
//		input : message id
//		output : string
//		comments : return the asked string in current language
////////////////////////////////////////////////////////////////////////////////////////
char *psp_msg_string(int num) {
	int msg_num=0;
	if (os9x_language == LANGUAGE_JAPANESE)
		while (msg_num<MSG_TOTAL_ENTRIES) {
			if (num==s9xTYL_msg_ja[msg_num].msg_id) return s9xTYL_msg_ja[msg_num].msg;
			msg_num++;
		}
	else
		while (msg_num<MSG_TOTAL_ENTRIES) {
			if (num==s9xTYL_msg_en[msg_num].msg_id) return s9xTYL_msg_en[msg_num].msg;
			msg_num++;
		}
	return "unknown string";//NULL;
}

////////////////////////////////////////////////////////////////////////////////////////
// psp_msg
// -------------- 
//		input : message id, display length
//		output : none
//		comments : show the message in current language.
//							 len allow display length value and special dialog selection
//							 ("yes/no" box or "ok" box).
////////////////////////////////////////////////////////////////////////////////////////
int psp_msg(int num,int len) {	
	int msg_num=0;

	if (os9x_language == LANGUAGE_JAPANESE)
		while (msg_num<MSG_TOTAL_ENTRIES) {
			if (num==s9xTYL_msg_ja[msg_num].msg_id) break;
			msg_num++;
		}
	else
		while (msg_num<MSG_TOTAL_ENTRIES) {
			if (num==s9xTYL_msg_en[msg_num].msg_id) break;
			msg_num++;
		}

	if (msg_num==MSG_TOTAL_ENTRIES) return 0;

	if (os9x_language == LANGUAGE_JAPANESE) {
		if (len==MSG_DEFAULT)	len=s9xTYL_msg_ja[msg_num].len;
		if (len>=0)	msgBoxLines(s9xTYL_msg_ja[msg_num].msg,s9xTYL_msg_ja[msg_num].len);
		else if (len==-1) inputBoxOK(s9xTYL_msg_ja[msg_num].msg);
		else if (len==-2) return inputBox(s9xTYL_msg_ja[msg_num].msg);
	}
	else {
		if (len==MSG_DEFAULT)	len=s9xTYL_msg_en[msg_num].len;
		if (len>=0)	msgBoxLines(s9xTYL_msg_en[msg_num].msg,s9xTYL_msg_en[msg_num].len);
		else if (len==-1) inputBoxOK(s9xTYL_msg_en[msg_num].msg);
		else if (len==-2) return inputBox(s9xTYL_msg_en[msg_num].msg);
	}

	return 0;
}

