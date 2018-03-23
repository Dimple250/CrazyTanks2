#ifndef LEVEL_H
#define LEVEL_H

const int LEVELROWS = 20;
const int LEVELCOLS = 50;

const unsigned char SPLAYER = '@';
const unsigned char SENEMY = 'X';
const unsigned char SWALL = '#';
const unsigned char SBREAKWALL = '%';

const unsigned char LEVEDATA0[LEVELROWS][LEVELCOLS + 1] = {
	"##################################################",
	"#                                                #",
	"#                                                #",
	"#                 X   %%%%%%%%%%%                #",
	"#       %%%%%%%%                                 #",
	"#                                    X           #",
	"#                                                #",
	"#       X                                        #",
	"#                 %%  X        %%%%%%%%          #",
	"#                 %%                             #",
	"#       %%        %%                             #",
	"#       %%        %%                             #",
	"#       %%                                       #",
	"#       %%                                       #",
	"#       %%                                       #",
	"#                                  @             #",
	"#                   %%%%%%%%%                    #",
	"#                   %%     %%                    #",
	"#                   %%  $  %%                    #",
	"##################################################"
};

#endif /* LEVEL_H */