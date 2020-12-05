# NFSMW Race Fixes
NFSMW Race Fixes is a mod package which contains fixes and improvements for race modes.
Here is what we have done so far:
+ Fixed race selection crash for LAN races. (Transferred from Extra Options.)
+ Fixed race names and icons for LAN races. (Transferred from Extra Options.)
+ Added Tollbooth, Challenge, Token Pickup and Cashgrab race modes to Quick Race Menu. (Only Tollbooth is enabled by default.)
+ Added a game option to enable cops in the race. (Transferred from Extra Options.)
* Forced lap count to 1 for point-to-point (Sprint, Drag, etc.) race modes.
* Forced heat level to maximum for Challenge race mode.
* Forced opponent count to 0 for Token Pickup and Challenge race modes.
+ Restored Cashgrab race mode:
- Added to the Quick Race menu.
- Track select screen will now show best cash instead of the time.
- Added on-screen messages when the player gets a cash bag.
- Leaderboard is fixed.
- Post Race stats are almost fixed. (Cash Bags / Stages page is empty.)

# Technical Information
If you want everything to work properly:

1) You will need to add these textures in your GLOBAL\\GlobalB.bun/lzc, GlobalTextures.tpk:
```
97C5B6A0 - MODE_ICON_MULTIPOINT_TOKEN
CE985A7A - MODE_ICON_MULTIPOINT_CASHGRAB
```

2) You will need to add these strings into your LANGUAGES\\(LanguageName).bin:
```
0D0C9448 - RACETYPES_CASH_GRAB - "Cashgrab"
34FACD79 - PRS_ACCUMULATED_CASH - "Accumulated Cash"
3E602952 - PRR_CASH_TITLE - "Cash"
482039FA - PRS_CASH_VARIANCE - "Cash Variance"
634BA8DA - RACETYPES_TOKEN_PICKUP - "Token Pickup"
9A77C9A7 - PRR_TOKENS_TITLE - "Tokens"
CF2BDD31 - HIGHEST_CASH_HEADER - "Best Cash"
F27395FE - PRR_CASHBAGS_RESULTS_BUTTON_TEXT - "Cash Bags"
D8E59B16 - TOKEN_PICKUP_OPTIONS - "token pickup options"
25110F85 - CASHGRAB_OPTIONS - "cashgrab options"
12FA6FAD - CHALLENGE_OPTIONS - "challenge options"
```

Note: Binary scripts which will do these automatically for you are available in the release pack.

# Download
To download, please check out the releases page.
