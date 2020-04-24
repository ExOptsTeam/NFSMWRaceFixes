# NFSMW Race Fixes
NFSMW Race Fixes is a mod package which contains fixes and improvements for race modes.
Here is what we have done so far:
+ Fixed race selection crash for LAN races. (Transferred from Extra Options.)
+ Fixed race names and icons for LAN races. (Transferred from Extra Options.)
+ Restored Cashgrab race mode:
- Added to the Quick Race menu.
- Track select screen will now show best cash instead of the time.
- Added on-screen messages when the player gets a cash bag.
- Leaderboard is fixed.
- Post Race stats are almost fixed. (Cash Bags / Stages page is empty.)

# Technical Information
If you want everything to work properly:

1) You will need to add these textures in your GlobalB.bun/lzc, GlobalTextures.tpk:
```
586A39A2 - MODE_ICON_MULTIPOINT_TO
CE985A7A - MODE_ICON_MULTIPOINT_CASHGRAB
```

2) You will need to add these strings into your LANGUAGES\(LanguageName).bin:
```
1E5F2565 - RACETYPES_MULTIPOINT_TO - "Multipoint"
34FACD79 - PRS_ACCUMULATED_CASH - "Accumulated Cash"
482039FA - PRS_CASH_VARIANCE - "Cash Variance"
93EDCC7D - RACETYPES_MULTIPOINT_CASHGRAB - "Cashgrab"
CF2BDD31 - HIGHEST_CASH_HEADER - "Best Cash"
F27395FE - PRR_CASHBAGS_RESULTS_BUTTON_TEXT - "Cash Bags"
```

Note: Binary scripts which will do these automatically for you will be available with the first public release.

# Download
No downloads yet, however, the first milestone of this mod will be available in elaymm4's NFSMW Beta Content Mod.
