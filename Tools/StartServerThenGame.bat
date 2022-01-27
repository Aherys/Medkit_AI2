start /D "C:\Program Files (x86)\Steam\steamapps\common\DayZServer\" DayZDiag_x64.exe -server "-config=serverDZ.cfg" "-mod=@PA_Box;P:\Medkit_AI2;@CF;@VPPNotifications;@VPPAdminTools" -dologs -adminlog -freezecheck -filePatching "-profiles=Profiles/"

TIMEOUT 5

start /D "C:\Program Files (x86)\Steam\steamapps\common\DayZ" DayZDiag_x64.exe "-mod=@PA_Box;P:\Medkit_AI2;!Workshop\@CF;!Workshop\@VPPNotifications;!Workshop\@VPPAdminTools" -filePatching "Aherys" -dologs -adminlog -freezecheck "-scriptDebug=true" -connect=127.0.0.1:2302 "-profiles=Profiles/" -window
