# NFSMW Race Fixes
NFSMW Race Fixes is a mod package which contains fixes and improvements for race modes.  
Here is what we have done so far:  
```
+ Fixed race selection crash for LAN races. (Transferred from Extra Options.)
+ Fixed race names and icons for LAN races. (Transferred from Extra Options.)
+ Added Tollbooth, Challenge, Token Pickup and Cashgrab race modes to Quick Race Menu. (Only Tollbooth is enabled by default.)
+ Added a game option to enable cops in the race. (Transferred from Extra Options.)
+ Added a game option to set any pursuit condition (if the Heat level is set to at least Minimum) in the race.
* Forced lap count to 1 for point-to-point (Sprint, Drag, etc.) race modes.
* Forced heat level to maximum for Challenge race mode.
* Forced opponent count to 0 for Token Pickup and Challenge race modes.
+ Fixed hardcoded "Tollbooth" icon for the races in Challenge Series.
+ Assigned icons for the unused milestone types. (Special thanks to LunicAura for making those icons for us from scratch!)
+ Restored Cashgrab race mode:
    - Added to the Quick Race menu.
    - Track select screen will now show best cash instead of the time.
    - Added on-screen messages when the player gets a cash bag.
    - Leaderboard is fixed.
    - Post Race stats are almost fixed. (Cash Bags / Stages page is empty.)
```

# Technical Information
To make everything work properly, we had to make some changes in the game files.  

1) Added new strings:  
| String hash   | String label                      | Text (in English)                      | Destination                          |
| ------------- | --------------------------------- | -------------------------------------- | ------------------------------------ |
| 0x0D0C9448    | RACETYPES_CASH_GRAB               | "Cashgrab"                             | Languages\<LANGUAGENAME>.bin         |
| 0x634BA8DA    | RACETYPES_TOKEN_PICKUP            | "Token Pickup"                         | Languages\<LANGUAGENAME>.bin         |
| 0x34FACD79    | PRS_ACCUMULATED_CASH              | "Accumulated Cash"                     | Languages\<LANGUAGENAME>.bin         |
| 0x3E602952    | PRR_CASH_TITLE                    | "Cash"                                 | Languages\<LANGUAGENAME>.bin         |
| 0x482039FA    | PRS_CASH_VARIANCE                 | "Cash Variance"                        | Languages\<LANGUAGENAME>.bin         |
| 0x9A77C9A7    | PRR_TOKENS_TITLE                  | "Tokens"                               | Languages\<LANGUAGENAME>.bin         |
| 0xCF2BDD31    | HIGHEST_CASH_HEADER               | "Best Cash"                            | Languages\<LANGUAGENAME>.bin         |
| 0xF27395FE    | PRR_CASHBAGS_RESULTS_BUTTON_TEXT  | "Cash Bags"                            | Languages\<LANGUAGENAME>.bin         |
| 0x25110F85    | CASHGRAB_OPTIONS                  | "cashgrab options"                     | Languages\<LANGUAGENAME>.bin         |
| 0xD8E59B16    | TOKEN_PICKUP_OPTIONS              | "token pickup options"                 | Languages\<LANGUAGENAME>.bin         |
| 0x12FA6FAD    | CHALLENGE_OPTIONS                 | "challenge options"                    | Languages\<LANGUAGENAME>.bin         |
| 0x1D7DF65A    | QR_OPT_CONDITION                  | "Condition"                            | Languages\<LANGUAGENAME>.bin         |
| 0x096F8B1E    | TRACK_SELECT_TOKEN_PICKUP         | "token pickup track select"            | Languages\<LANGUAGENAME>.bin         |
| 0x4F5DFD0C    | TRACK_SELECT_CASH_GRAB            | "cashgrab track select"                | Languages\<LANGUAGENAME>.bin         |
| 0x638E3195    | TRACK_SELECT_CHALLENGE            | "challenge track select"               | Languages\<LANGUAGENAME>.bin         |

2) Added new textures:  
| Texture hash  | Texture name                  | Destination                            |
| ------------- | ----------------------------- | -------------------------------------- |
| 0x03B2DD3C    | MILESTONE_RECKLESS_DRIVING    | Global\GlobalB.lzc, GlobalTextures.tpk |
| 0x045FF871    | MILESTONE_PROPERTY_DAMAGE     | Global\GlobalB.lzc, GlobalTextures.tpk |
| 0x054F9862    | MILESTONE_SPEEDING            | Global\GlobalB.lzc, GlobalTextures.tpk |
| 0x0E4D7989    | MILESTONE_911                 | Global\GlobalB.lzc, GlobalTextures.tpk |
| 0x38F042FB    | MILESTONE_OUTRUN_RACES_WON    | Global\GlobalB.lzc, GlobalTextures.tpk |
| 0x97C5B6A0    | MODE_ICON_MULTIPOINT_TOKEN    | Global\GlobalB.lzc, GlobalTextures.tpk |
| 0xA2680BB6    | MILESTONE_RESISTING_ARREST    | Global\GlobalB.lzc, GlobalTextures.tpk |
| 0xB3804556    | MILESTONE_OPPONENTS_DAMAGED   | Global\GlobalB.lzc, GlobalTextures.tpk |
| 0xC15BFBB6    | MILESTONE_HITNRUN             | Global\GlobalB.lzc, GlobalTextures.tpk |
| 0xC7280BAF    | MILESTONE_MARGIN_OF_VICTORY   | Global\GlobalB.lzc, GlobalTextures.tpk |
| 0xCE985A7A    | MODE_ICON_MULTIPOINT_CASHGRAB | Global\GlobalB.lzc, GlobalTextures.tpk |
| 0xD0C4EABC    | MILESTONE_OUTRUN_PURSUITS_WON | Global\GlobalB.lzc, GlobalTextures.tpk |
| 0xD438F62F    | MILESTONE_OFFROAD             | Global\GlobalB.lzc, GlobalTextures.tpk |
| 0xD8053BD0    | MILESTONE_HEAT                | Global\GlobalB.lzc, GlobalTextures.tpk |

3) Moved some textures from other game files:  
| Texture hash  | Texture name                  | Source                                                                                | Destination                            |
| ------------- | ----------------------------- | ------------------------------------------------------------------------------------- | -------------------------------------- |
| 0x3787231C    | COPS_ICON                     | Global\HUDTexRace.bin, HUDTexturesSingleRace.tpk                                      | Global\GlobalB.lzc, GlobalTextures.tpk |
| 0x4E6FBB02    | MAIN_ICON_QUICK_RACE          | FrontEnd\FrontB.lzc, FrontEndTextures.tpk                                             | Global\GlobalB.lzc, GlobalTextures.tpk |
| 0x9A962438    | MODE_ICON_CHALLENGE_SERIES    | FrontEnd\FrontB.lzc, FrontEndTextures.tpk                                             | Global\GlobalB.lzc, GlobalTextures.tpk |
| 0xD807E9B3    | MILESTONE_MAIN                | FrontEnd\FrontB.lzc, FrontEndTextures.tpk & Global\InGameA.bun, InGameTextures.tpk    | Global\GlobalB.lzc, GlobalTextures.tpk |
| 0xF66AC1B6    | HELICOPTER_ICON               | Global\HUDTexRace.bin, HUDTexturesSingleRace.tpk                                      | Global\GlobalB.lzc, GlobalTextures.tpk |


**Don't worry**, **Binary** scripts which will do these automatically for you with the required files are available in the [release pack](https://www.github.com/ExOptsTeam/NFSMWRaceFixes/releases/latest).
Just import **_NFSMWRaceFixes-Setup-Binary.end** file via [Binary by MaxHwoy](https://github.com/SpeedReflect/Binary) **v2.8.3** or up in **User mode**.

# Download
To download, please check out the [releases page](https://www.github.com/ExOptsTeam/NFSMWRaceFixes/releases).  
