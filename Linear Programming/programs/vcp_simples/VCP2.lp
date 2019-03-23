\* Problem: VCP2 *\

Minimize
 obj: + x0 + x1 + x2 + x3 + x4 + x5 + x6 + x7 + x8 + x9 + x10 + x11
 + x12 + x13 + x14 + x15 + x16 + x17 + x18 + x19 + x20 + x21 + x22 + x23
 + x24 + x25 + x26 + x27 + x28 + x29 + x30 + x31 + x32 + x33 + x34 + x35
 + x36 + x37 + x38 + x39 + x40 + x41 + x42 + x43 + x44 + x45 + x46 + x47
 + x48 + x49 + x50 + x51 + x52 + x53 + x54 + x55 + x56 + x57 + x58 + x59
 + x60 + x61 + x62 + x63 + x64 + x65 + x66 + x67 + x68 + x69 + x70 + x71
 + x72 + x73 + x74 + x75 + x76 + x77 + x78 + x79 + x80 + x81 + x82 + x83
 + x84 + x85 + x86 + x87 + x88 + x89 + x90 + x91 + x92 + x93 + x94 + x95
 + x96 + x97 + x98 + x99

Subject To
 clique1: + x0 + x1 + x2 + x3 + x7 + x9 + x15 + x22 + x23 + x25 + x27
 + x31 + x47 + x54 + x75 >= 14
 clique2: + x0 + x4 + x5 + x6 + x8 + x10 + x29 + x35 + x43 + x46 + x53
 + x55 + x61 + x65 + x91 >= 14
 clique3: + x0 + x16 + x18 + x24 + x26 + x39 + x40 + x50 + x51 + x57
 + x63 + x71 + x72 + x90 >= 13
 clique4: + x0 + x19 + x28 + x37 + x42 + x45 + x56 + x60 + x64 + x68
 >= 9
 clique5: + x0 + x32 + x33 + x34 + x48 + x58 + x59 + x92 + x93 >= 8
 clique6: + x0 + x36 + x62 + x70 + x73 + x79 + x82 + x84 + x97 + x98
 >= 9
 clique7: + x0 + x67 + x74 + x80 + x86 + x87 + x89 + x99 >= 7
 clique8: + x0 + x81 + x83 + x85 + x95 >= 4
 clique9: + x1 + x6 + x11 + x13 + x16 + x28 + x30 + x32 + x62 + x78
 + x80 >= 10
 clique10: + x1 + x8 + x17 + x18 + x19 + x21 + x66 + x70 + x85 + x92
 >= 9
 clique11: + x1 + x10 + x12 + x20 + x24 + x38 + x44 + x59 + x67 >= 8
 clique12: + x1 + x33 + x35 + x36 + x39 + x45 + x77 + x81 + x88 + x89
 >= 9
 clique13: + x1 + x34 + x41 + x52 + x56 + x61 + x72 + x73 + x74 >= 8
 clique14: + x1 + x40 + x42 + x43 + x58 + x69 + x87 + x96 >= 7
 clique15: + x1 + x48 + x50 + x55 + x84 >= 4
 clique16: + x1 + x53 + x68 + x71 + x79 + x95 + x99 >= 6
 clique17: + x1 + x63 + x76 + x86 + x91 + x98 >= 5
 clique18: + x1 + x82 + x90 >= 2
 clique19: + x1 + x94 + x97 >= 2
 clique20: + x2 + x4 + x11 + x14 + x38 + x39 + x66 + x73 + x76 + x96
 >= 9
 clique21: + x2 + x5 + x12 + x17 + x26 + x33 + x42 + x80 + x82 >= 8
 clique22: + x2 + x6 + x18 + x44 + x49 + x56 + x79 + x89 >= 7
 clique23: + x2 + x10 + x16 + x21 + x45 + x83 + x86 >= 6
 clique24: + x2 + x19 + x20 + x29 + x34 + x50 >= 5
 clique25: + x2 + x24 + x30 + x41 + x65 + x81 + x93 + x97 >= 7
 clique26: + x2 + x43 + x51 + x52 + x68 + x77 >= 5
 clique27: + x2 + x48 + x60 + x62 + x69 + x88 + x90 >= 6
 clique28: + x2 + x53 + x57 + x58 + x64 + x78 >= 5
 clique29: + x2 + x55 + x63 + x67 + x85 >= 4
 clique30: + x2 + x59 + x72 + x87 >= 3
 clique31: + x2 + x74 + x84 + x91 + x92 >= 4
 clique32: + x2 + x95 >= 1
 clique33: + x2 + x99 >= 1
 clique34: + x3 + x4 + x13 + x21 + x36 + x37 + x40 + x99 >= 7
 clique35: + x3 + x5 + x11 + x34 + x69 + x77 + x85 + x98 >= 7
 clique36: + x3 + x8 + x14 + x28 + x41 + x49 + x86 + x88 >= 7
 clique37: + x3 + x10 + x17 + x30 + x63 + x64 + x79 >= 6
 clique38: + x3 + x12 + x19 + x43 + x62 + x83 + x93 >= 6
 clique39: + x3 + x26 + x32 + x44 + x45 + x46 + x70 >= 6
 clique40: + x3 + x33 + x38 + x55 + x68 + x90 + x94 >= 6
 clique41: + x3 + x42 + x50 + x52 + x65 + x66 + x89 >= 6
 clique42: + x3 + x51 + x58 + x61 + x76 + x97 >= 5
 clique43: + x3 + x59 + x71 + x73 + x78 + x91 >= 5
 clique44: + x3 + x67 + x96 >= 2
 clique45: + x3 + x80 >= 1
 clique46: + x4 + x7 + x18 + x33 + x62 + x86 >= 5
 clique47: + x4 + x9 + x17 + x34 + x45 + x57 + x87 >= 6
 clique48: + x4 + x15 + x26 + x28 + x52 + x59 + x95 + x97 >= 7
 clique49: + x4 + x22 + x32 + x49 + x67 + x77 + x84 + x94 >= 7
 clique50: + x4 + x23 + x44 + x60 + x81 >= 4
 clique51: + x4 + x25 + x48 + x63 + x68 >= 4
 clique52: + x4 + x27 + x50 + x78 + x79 + x83 + x92 >= 6
 clique53: + x4 + x31 + x51 + x69 >= 3
 clique54: + x4 + x47 + x71 + x74 + x85 >= 4
 clique55: + x4 + x54 + x72 + x88 >= 3
 clique56: + x4 + x75 + x89 + x93 >= 3
 clique57: + x4 + x90 >= 1
 clique58: + x5 + x7 + x13 + x14 + x44 + x50 + x94 >= 6
 clique59: + x5 + x16 + x20 + x22 + x41 + x68 + x89 >= 6
 clique60: + x5 + x21 + x23 + x28 + x67 + x71 >= 5
 clique61: + x5 + x25 + x30 + x38 + x49 + x83 >= 5
 clique62: + x5 + x36 + x47 + x48 + x72 + x76 >= 5
 clique63: + x5 + x51 + x56 + x66 + x75 + x78 + x95 >= 6
 clique64: + x5 + x54 + x57 + x73 + x81 >= 4
 clique65: + x5 + x58 + x88 >= 2
 clique66: + x5 + x79 + x87 + x90 >= 3
 clique67: + x5 + x86 + x93 >= 2
 clique68: + x5 + x97 + x99 >= 2
 clique69: + x6 + x7 + x20 + x21 + x52 + x90 >= 5
 clique70: + x6 + x9 + x14 + x26 + x36 + x60 + x67 >= 6
 clique71: + x6 + x17 + x27 + x40 + x41 + x94 >= 5
 clique72: + x6 + x19 + x23 + x73 + x95 >= 4
 clique73: + x6 + x22 + x37 + x38 + x51 + x70 + x88 >= 6
 clique74: + x6 + x31 + x39 + x42 + x74 + x98 >= 5
 clique75: + x6 + x45 + x47 + x58 >= 3
 clique76: + x6 + x54 + x59 + x66 + x68 + x82 + x86 >= 6
 clique77: + x6 + x57 + x75 + x76 + x84 + x85 >= 5
 clique78: + x6 + x64 + x71 + x81 + x96 >= 4
 clique79: + x6 + x72 + x83 >= 2
 clique80: + x6 + x87 + x97 >= 2
 clique81: + x6 + x92 + x99 >= 2
 clique82: + x7 + x8 + x24 + x58 + x73 + x77 >= 5
 clique83: + x7 + x11 + x12 + x29 + x41 + x87 >= 5
 clique84: + x7 + x16 + x35 + x38 + x69 + x92 >= 5
 clique85: + x7 + x26 + x37 + x49 + x61 + x66 >= 5
 clique86: + x7 + x30 + x39 + x46 + x56 >= 4
 clique87: + x7 + x43 + x57 + x80 + x88 >= 4
 clique88: + x7 + x55 + x64 + x72 + x98 + x99 >= 5
 clique89: + x7 + x59 + x63 + x81 >= 3
 clique90: + x7 + x67 + x68 + x83 >= 3
 clique91: + x7 + x71 + x89 >= 2
 clique92: + x7 + x76 + x79 >= 2
 clique93: + x7 + x78 + x82 >= 2
 clique94: + x7 + x84 >= 1
 clique95: + x7 + x91 >= 1
 clique96: + x8 + x9 + x20 + x37 + x72 + x81 >= 5
 clique97: + x8 + x13 + x22 + x59 + x64 + x76 + x90 >= 6
 clique98: + x8 + x23 + x30 + x33 + x69 >= 4
 clique99: + x8 + x25 + x32 + x39 + x52 + x82 >= 5
 clique100: + x8 + x31 + x34 + x36 + x83 >= 4
 clique101: + x8 + x40 + x45 + x48 + x54 + x98 >= 5
 clique102: + x8 + x42 + x51 + x99 >= 3
 clique103: + x8 + x50 + x60 + x75 + x96 >= 4
 clique104: + x8 + x57 + x62 + x74 >= 3
 clique105: + x8 + x63 + x78 + x93 + x94 >= 4
 clique106: + x8 + x71 >= 1
 clique107: + x8 + x89 >= 1
 clique108: + x9 + x10 + x11 + x19 + x33 + x40 + x74 >= 6
 clique109: + x9 + x12 + x18 + x28 + x35 >= 4
 clique110: + x9 + x24 + x29 + x52 + x79 >= 4
 clique111: + x9 + x30 + x42 + x44 + x53 + x77 >= 5
 clique112: + x9 + x39 + x41 + x80 + x84 + x95 >= 5
 clique113: + x9 + x43 + x49 + x50 + x64 + x82 >= 5
 clique114: + x9 + x46 + x51 + x89 + x94 >= 4
 clique115: + x9 + x55 + x56 + x69 + x86 >= 4
 clique116: + x9 + x58 + x68 + x98 >= 3
 clique117: + x9 + x61 + x63 >= 2
 clique118: + x9 + x65 + x78 + x90 >= 3
 clique119: + x9 + x66 + x71 + x93 >= 3
 clique120: + x9 + x76 + x88 >= 2
 clique121: + x9 + x83 + x91 + x96 >= 3
 clique122: + x9 + x97 >= 1
 clique123: + x9 + x99 >= 1
 clique124: + x10 + x13 + x25 + x26 + x73 + x85 + x89 >= 6
 clique125: + x10 + x14 + x15 + x48 + x56 + x71 >= 5
 clique126: + x10 + x23 + x34 + x37 + x97 >= 4
 clique127: + x10 + x27 + x36 + x49 + x68 + x69 >= 5
 clique128: + x10 + x31 + x50 + x62 + x76 + x99 >= 5
 clique129: + x10 + x39 + x54 + x92 >= 3
 clique130: + x10 + x42 + x47 + x57 + x95 >= 4
 clique131: + x10 + x52 + x60 + x78 + x87 >= 4
 clique132: + x10 + x75 + x82 >= 2
 clique133: + x10 + x88 + x94 >= 2
 clique134: + x10 + x90 >= 1
 clique135: + x10 + x93 >= 1
 clique136: + x11 + x15 + x20 + x35 + x60 + x93 + x99 >= 6
 clique137: + x11 + x22 + x24 + x43 + x56 >= 4
 clique138: + x11 + x23 + x36 + x46 + x58 >= 4
 clique139: + x11 + x25 + x37 + x84 + x90 >= 4
 clique140: + x11 + x27 + x45 + x51 + x53 + x59 >= 5
 clique141: + x11 + x31 + x48 + x64 + x65 >= 4
 clique142: + x11 + x47 + x63 + x70 >= 3
 clique143: + x11 + x55 + x71 + x75 >= 3
 clique144: + x11 + x67 + x82 + x91 >= 3
 clique145: + x11 + x68 >= 1
 clique146: + x11 + x83 + x89 >= 2
 clique147: + x11 + x92 >= 1
 clique148: + x11 + x94 >= 1
 clique149: + x12 + x13 + x27 + x46 + x88 + x96 >= 5
 clique150: + x12 + x14 + x23 + x32 + x53 + x85 >= 5
 clique151: + x12 + x21 + x25 + x51 + x64 + x91 >= 5
 clique152: + x12 + x30 + x31 + x45 + x52 + x55 >= 5
 clique153: + x12 + x34 + x39 + x99 >= 3
 clique154: + x12 + x37 + x50 + x54 + x58 >= 4
 clique155: + x12 + x47 + x49 + x60 + x98 >= 4
 clique156: + x12 + x57 + x66 + x94 >= 3
 clique157: + x12 + x63 + x84 >= 2
 clique158: + x12 + x69 + x70 + x72 >= 3
 clique159: + x12 + x76 + x81 >= 2
 clique160: + x12 + x78 + x89 + x97 >= 3
 clique161: + x12 + x92 >= 1
 clique162: + x13 + x18 + x29 + x31 + x38 + x60 >= 5
 clique163: + x13 + x19 + x24 + x47 + x91 >= 4
 clique164: + x13 + x33 + x43 + x70 + x71 >= 4
 clique165: + x13 + x42 + x49 + x54 + x55 + x93 >= 5
 clique166: + x13 + x45 + x61 + x67 + x79 >= 4
 clique167: + x13 + x48 + x74 + x75 + x83 >= 4
 clique168: + x13 + x51 + x65 + x84 >= 3
 clique169: + x13 + x53 + x69 + x81 >= 3
 clique170: + x13 + x57 + x77 + x86 + x92 >= 4
 clique171: + x13 + x58 + x95 >= 2
 clique172: + x13 + x87 >= 1
 clique173: + x14 + x18 + x22 + x55 + x78 >= 4
 clique174: + x14 + x20 + x27 + x64 + x70 + x87 >= 5
 clique175: + x14 + x24 + x31 + x46 + x80 >= 4
 clique176: + x14 + x29 + x30 + x40 + x75 >= 4
 clique177: + x14 + x35 + x47 + x52 + x62 >= 4
 clique178: + x14 + x43 + x54 >= 2
 clique179: + x14 + x61 + x77 + x82 >= 3
 clique180: + x14 + x69 + x79 + x93 >= 3
 clique181: + x14 + x84 + x89 >= 2
 clique182: + x14 + x92 + x98 >= 2
 clique183: + x15 + x16 + x17 + x36 + x44 + x61 >= 5
 clique184: + x15 + x18 + x32 + x37 + x43 + x98 >= 5
 clique185: + x15 + x19 + x30 + x51 + x67 >= 4
 clique186: + x15 + x21 + x24 + x55 + x74 + x96 >= 5
 clique187: + x15 + x33 + x46 + x50 + x85 >= 4
 clique188: + x15 + x34 + x38 + x64 + x80 >= 4
 clique189: + x15 + x39 + x49 + x53 + x62 >= 4
 clique190: + x15 + x40 + x65 + x73 + x83 >= 4
 clique191: + x15 + x41 + x42 + x76 + x92 >= 4
 clique192: + x15 + x45 + x66 + x90 + x91 >= 4
 clique193: + x15 + x57 + x79 >= 2
 clique194: + x15 + x58 + x89 >= 2
 clique195: + x15 + x63 + x77 >= 2
 clique196: + x15 + x72 + x82 >= 2
 clique197: + x15 + x78 + x81 >= 2
 clique198: + x15 + x86 + x94 >= 2
 clique199: + x16 + x23 + x42 + x70 >= 3
 clique200: + x16 + x25 + x33 + x53 + x60 + x76 >= 5
 clique201: + x16 + x27 + x34 + x43 + x66 >= 4
 clique202: + x16 + x31 + x37 + x82 >= 3
 clique203: + x16 + x46 + x47 + x64 >= 3
 clique204: + x16 + x48 + x49 + x95 >= 3
 clique205: + x16 + x54 + x56 + x65 + x96 >= 4
 clique206: + x16 + x55 + x58 >= 2
 clique207: + x16 + x59 + x75 + x94 + x98 >= 4
 clique208: + x16 + x67 + x73 + x93 >= 3
 clique209: + x16 + x74 + x77 >= 2
 clique210: + x16 + x81 + x87 + x91 >= 3
 clique211: + x16 + x84 + x88 >= 2
 clique212: + x16 + x97 >= 1
 clique213: + x16 + x99 >= 1
 clique214: + x17 + x24 + x25 + x86 >= 3
 clique215: + x17 + x29 + x32 + x56 + x90 >= 4
 clique216: + x17 + x31 + x43 + x73 >= 3
 clique217: + x17 + x35 + x51 + x74 >= 3
 clique218: + x17 + x37 + x46 + x48 >= 3
 clique219: + x17 + x47 + x59 + x65 >= 3
 clique220: + x17 + x53 + x67 >= 2
 clique221: + x17 + x55 + x62 + x77 >= 3
 clique222: + x17 + x60 + x89 >= 2
 clique223: + x17 + x68 + x81 >= 2
 clique224: + x17 + x69 + x78 >= 2
 clique225: + x17 + x72 + x93 + x96 >= 3
 clique226: + x17 + x83 >= 1
 clique227: + x17 + x91 + x95 >= 2
 clique228: + x17 + x97 >= 1
 clique229: + x17 + x99 >= 1
 clique230: + x18 + x23 + x48 + x82 >= 3
 clique231: + x18 + x25 + x34 + x46 >= 3
 clique232: + x18 + x36 + x53 + x93 >= 3
 clique233: + x18 + x42 + x61 + x75 >= 3
 clique234: + x18 + x47 + x68 + x84 >= 3
 clique235: + x18 + x52 + x69 + x83 >= 3
 clique236: + x18 + x58 + x94 >= 2
 clique237: + x18 + x59 + x88 >= 2
 clique238: + x18 + x64 + x74 + x95 >= 3
 clique239: + x18 + x65 + x77 >= 2
 clique240: + x18 + x91 >= 1
 clique241: + x18 + x97 >= 1
 clique242: + x19 + x27 + x38 + x52 >= 3
 clique243: + x19 + x31 + x41 + x53 >= 3
 clique244: + x19 + x44 + x54 + x76 >= 3
 clique245: + x19 + x46 + x49 + x63 >= 3
 clique246: + x19 + x55 + x57 >= 2
 clique247: + x19 + x61 + x81 + x90 >= 3
 clique248: + x19 + x65 + x69 + x75 >= 3
 clique249: + x19 + x71 + x77 >= 2
 clique250: + x19 + x72 + x79 >= 2
 clique251: + x19 + x82 >= 1
 clique252: + x19 + x84 >= 1
 clique253: + x19 + x94 >= 1
 clique254: + x19 + x96 >= 1
 clique255: + x20 + x23 + x26 + x55 >= 3
 clique256: + x20 + x25 + x28 + x36 + x65 >= 4
 clique257: + x20 + x31 + x32 + x61 >= 3
 clique258: + x20 + x39 + x75 + x79 >= 3
 clique259: + x20 + x40 + x46 + x76 >= 3
 clique260: + x20 + x42 + x63 + x73 >= 3
 clique261: + x20 + x47 + x78 >= 2
 clique262: + x20 + x49 + x57 >= 2
 clique263: + x20 + x53 + x54 + x74 + x97 >= 4
 clique264: + x20 + x66 + x77 + x80 >= 3
 clique265: + x20 + x83 + x84 >= 2
 clique266: + x20 + x85 + x86 >= 2
 clique267: + x20 + x91 + x94 >= 2
 clique268: + x20 + x95 >= 1
 clique269: + x20 + x98 >= 1
 clique270: + x21 + x22 + x29 + x69 + x97 >= 4
 clique271: + x21 + x27 + x32 + x35 + x42 >= 4
 clique272: + x21 + x31 + x44 + x63 >= 3
 clique273: + x21 + x38 + x41 + x46 + x78 >= 4
 clique274: + x21 + x43 + x84 >= 2
 clique275: + x21 + x47 + x61 + x89 >= 3
 clique276: + x21 + x50 + x53 + x88 + x98 >= 4
 clique277: + x21 + x56 + x59 >= 2
 clique278: + x21 + x65 + x79 >= 2
 clique279: + x21 + x68 >= 1
 clique280: + x21 + x76 + x82 + x95 >= 3
 clique281: + x21 + x94 >= 1
 clique282: + x22 + x26 + x34 + x65 + x86 >= 4
 clique283: + x22 + x28 + x39 + x61 + x93 >= 4
 clique284: + x22 + x30 + x50 + x91 >= 3
 clique285: + x22 + x40 + x53 + x82 >= 3
 clique286: + x22 + x58 + x62 >= 2
 clique287: + x22 + x72 >= 1
 clique288: + x22 + x73 + x99 >= 2
 clique289: + x22 + x74 + x79 >= 2
 clique290: + x22 + x95 + x96 >= 2
 clique291: + x22 + x98 >= 1
 clique292: + x23 + x24 + x49 + x92 >= 3
 clique293: + x23 + x29 + x45 + x94 + x99 >= 4
 clique294: + x23 + x35 + x59 >= 2
 clique295: + x23 + x62 + x63 + x65 >= 3
 clique296: + x23 + x64 + x66 >= 2
 clique297: + x23 + x68 + x74 >= 2
 clique298: + x23 + x76 + x77 >= 2
 clique299: + x23 + x88 + x91 >= 2
 clique300: + x23 + x89 + x98 >= 2
 clique301: + x23 + x93 >= 1
 clique302: + x24 + x48 + x66 + x99 >= 3
 clique303: + x24 + x54 + x60 >= 2
 clique304: + x24 + x62 + x75 >= 2
 clique305: + x24 + x70 >= 1
 clique306: + x24 + x83 + x87 + x88 >= 3
 clique307: + x24 + x85 >= 1
 clique308: + x24 + x95 >= 1
 clique309: + x24 + x98 >= 1
 clique310: + x25 + x29 + x42 + x72 >= 3
 clique311: + x25 + x35 + x40 + x70 + x78 >= 4
 clique312: + x25 + x41 + x45 >= 2
 clique313: + x25 + x43 + x44 + x97 >= 3
 clique314: + x25 + x55 + x81 >= 2
 clique315: + x25 + x57 + x59 + x61 + x96 >= 4
 clique316: + x25 + x66 + x74 + x88 >= 3
 clique317: + x25 + x77 + x79 >= 2
 clique318: + x25 + x87 + x93 >= 2
 clique319: + x25 + x92 >= 1
 clique320: + x25 + x94 + x95 >= 2
 clique321: + x26 + x27 + x58 >= 2
 clique322: + x26 + x29 + x54 + x77 + x78 >= 4
 clique323: + x26 + x31 + x56 + x88 + x92 >= 4
 clique324: + x26 + x35 + x41 + x79 >= 3
 clique325: + x26 + x47 + x69 + x99 >= 3
 clique326: + x26 + x62 + x64 >= 2
 clique327: + x26 + x68 + x75 >= 2
 clique328: + x26 + x74 + x76 >= 2
 clique329: + x26 + x83 >= 1
 clique330: + x26 + x84 + x87 >= 2
 clique331: + x26 + x91 + x93 >= 2
 clique332: + x26 + x96 >= 1
 clique333: + x27 + x28 + x48 + x89 >= 3
 clique334: + x27 + x30 + x85 + x90 >= 3
 clique335: + x27 + x33 + x63 + x95 >= 3
 clique336: + x27 + x39 + x55 + x97 >= 3
 clique337: + x27 + x65 + x72 >= 2
 clique338: + x27 + x67 + x76 >= 2
 clique339: + x27 + x77 >= 1
 clique340: + x27 + x80 + x93 >= 2
 clique341: + x27 + x84 + x86 >= 2
 clique342: + x27 + x98 >= 1
 clique343: + x28 + x29 + x57 >= 2
 clique344: + x28 + x43 + x63 + x92 >= 3
 clique345: + x28 + x46 + x54 + x83 + x90 >= 4
 clique346: + x28 + x50 + x74 >= 2
 clique347: + x28 + x51 + x73 >= 2
 clique348: + x28 + x53 + x75 >= 2
 clique349: + x28 + x55 >= 1
 clique350: + x28 + x58 >= 1
 clique351: + x28 + x66 + x98 >= 2
 clique352: + x28 + x69 + x76 >= 2
 clique353: + x28 + x77 + x96 >= 2
 clique354: + x28 + x82 >= 1
 clique355: + x28 + x84 >= 1
 clique356: + x28 + x99 >= 1
 clique357: + x29 + x33 + x44 + x64 >= 3
 clique358: + x29 + x39 + x68 >= 2
 clique359: + x29 + x48 + x81 >= 2
 clique360: + x29 + x58 + x70 >= 2
 clique361: + x29 + x62 + x89 >= 2
 clique362: + x29 + x63 >= 1
 clique363: + x29 + x71 + x80 >= 2
 clique364: + x29 + x74 + x93 >= 2
 clique365: + x29 + x76 >= 1
 clique366: + x29 + x85 >= 1
 clique367: + x29 + x86 >= 1
 clique368: + x30 + x34 + x47 + x88 >= 3
 clique369: + x30 + x48 + x61 >= 2
 clique370: + x30 + x54 + x71 >= 2
 clique371: + x30 + x57 + x68 >= 2
 clique372: + x30 + x58 >= 1
 clique373: + x30 + x59 + x89 >= 2
 clique374: + x30 + x66 >= 1
 clique375: + x30 + x73 + x94 >= 2
 clique376: + x30 + x87 >= 1
 clique377: + x30 + x95 >= 1
 clique378: + x30 + x96 >= 1
 clique379: + x31 + x33 + x57 + x97 >= 3
 clique380: + x31 + x49 + x58 >= 2
 clique381: + x31 + x66 + x79 >= 2
 clique382: + x31 + x68 + x70 >= 2
 clique383: + x31 + x71 + x86 >= 2
 clique384: + x31 + x78 + x84 >= 2
 clique385: + x31 + x81 >= 1
 clique386: + x31 + x85 >= 1
 clique387: + x31 + x90 >= 1
 clique388: + x31 + x91 >= 1
 clique389: + x31 + x93 >= 1
 clique390: + x31 + x94 >= 1
 clique391: + x32 + x38 + x47 + x81 >= 3
 clique392: + x32 + x41 + x54 + x91 >= 3
 clique393: + x32 + x51 + x96 >= 2
 clique394: + x32 + x60 + x65 >= 2
 clique395: + x32 + x63 + x66 >= 2
 clique396: + x32 + x71 >= 1
 clique397: + x32 + x72 + x75 >= 2
 clique398: + x32 + x73 >= 1
 clique399: + x32 + x74 >= 1
 clique400: + x32 + x76 + x89 >= 2
 clique401: + x32 + x88 + x95 >= 2
 clique402: + x32 + x99 >= 1
 clique403: + x33 + x47 + x73 >= 2
 clique404: + x33 + x56 + x98 >= 2
 clique405: + x33 + x61 + x78 >= 2
 clique406: + x33 + x65 >= 1
 clique407: + x33 + x66 + x72 >= 2
 clique408: + x33 + x75 + x99 >= 2
 clique409: + x33 + x83 >= 1
 clique410: + x33 + x84 >= 1
 clique411: + x34 + x35 + x63 >= 2
 clique412: + x34 + x55 + x70 >= 2
 clique413: + x34 + x60 + x84 >= 2
 clique414: + x34 + x75 >= 1
 clique415: + x34 + x76 >= 1
 clique416: + x34 + x78 + x96 >= 2
 clique417: + x34 + x81 >= 1
 clique418: + x34 + x90 + x95 >= 2
 clique419: + x34 + x91 >= 1
 clique420: + x35 + x44 + x57 + x82 + x83 >= 4
 clique421: + x35 + x49 + x73 >= 2
 clique422: + x35 + x50 + x67 >= 2
 clique423: + x35 + x54 + x80 >= 2
 clique424: + x35 + x68 + x85 + x97 >= 3
 clique425: + x35 + x71 + x94 >= 2
 clique426: + x35 + x72 + x86 >= 2
 clique427: + x35 + x76 + x87 >= 2
 clique428: + x35 + x95 >= 1
 clique429: + x35 + x96 >= 1
 clique430: + x36 + x38 + x56 + x91 >= 3
 clique431: + x36 + x41 + x66 >= 2
 clique432: + x36 + x50 + x86 >= 2
 clique433: + x36 + x51 + x80 >= 2
 clique434: + x36 + x59 + x85 >= 2
 clique435: + x36 + x64 + x92 >= 2
 clique436: + x36 + x87 + x94 >= 2
 clique437: + x36 + x95 >= 1
 clique438: + x36 + x96 >= 1
 clique439: + x37 + x41 + x57 >= 2
 clique440: + x37 + x44 + x62 >= 2
 clique441: + x37 + x52 + x86 + x96 >= 3
 clique442: + x37 + x74 >= 1
 clique443: + x37 + x77 + x87 >= 2
 clique444: + x37 + x83 >= 1
 clique445: + x37 + x85 >= 1
 clique446: + x37 + x89 + x92 >= 2
 clique447: + x37 + x93 >= 1
 clique448: + x38 + x40 + x86 + x97 >= 3
 clique449: + x38 + x42 + x62 >= 2
 clique450: + x38 + x43 + x45 + x75 >= 3
 clique451: + x38 + x48 + x85 >= 2
 clique452: + x38 + x53 + x89 >= 2
 clique453: + x38 + x54 + x61 + x95 >= 3
 clique454: + x38 + x65 + x74 + x82 >= 3
 clique455: + x38 + x72 + x77 >= 2
 clique456: + x38 + x84 >= 1
 clique457: + x38 + x99 >= 1
 clique458: + x39 + x59 >= 1
 clique459: + x39 + x64 + x86 >= 2
 clique460: + x39 + x65 >= 1
 clique461: + x39 + x91 >= 1
 clique462: + x39 + x94 >= 1
 clique463: + x40 + x47 + x67 >= 2
 clique464: + x40 + x49 + x52 >= 2
 clique465: + x40 + x55 + x92 >= 2
 clique466: + x40 + x56 + x93 >= 2
 clique467: + x40 + x59 + x60 >= 2
 clique468: + x40 + x64 + x89 >= 2
 clique469: + x40 + x68 >= 1
 clique470: + x40 + x81 >= 1
 clique471: + x40 + x88 >= 1
 clique472: + x40 + x91 >= 1
 clique473: + x41 + x47 + x83 >= 2
 clique474: + x41 + x60 + x70 >= 2
 clique475: + x41 + x62 >= 1
 clique476: + x41 + x67 + x69 >= 2
 clique477: + x41 + x71 + x98 >= 2
 clique478: + x41 + x75 >= 1
 clique479: + x41 + x82 >= 1
 clique480: + x41 + x85 >= 1
 clique481: + x41 + x90 >= 1
 clique482: + x42 + x46 + x71 >= 2
 clique483: + x42 + x67 + x88 >= 2
 clique484: + x42 + x79 + x85 >= 2
 clique485: + x42 + x81 >= 1
 clique486: + x42 + x84 >= 1
 clique487: + x42 + x86 + x90 >= 2
 clique488: + x42 + x91 >= 1
 clique489: + x43 + x72 + x94 >= 2
 clique490: + x43 + x78 >= 1
 clique491: + x43 + x81 + x99 >= 2
 clique492: + x43 + x90 >= 1
 clique493: + x44 + x47 + x90 >= 2
 clique494: + x44 + x51 + x98 >= 2
 clique495: + x44 + x55 + x73 >= 2
 clique496: + x44 + x58 + x80 >= 2
 clique497: + x44 + x68 >= 1
 clique498: + x44 + x69 + x84 >= 2
 clique499: + x44 + x72 + x85 >= 2
 clique500: + x44 + x74 + x78 >= 2
 clique501: + x44 + x91 + x99 >= 2
 clique502: + x44 + x95 >= 1
 clique503: + x45 + x49 + x65 + x80 >= 3
 clique504: + x45 + x50 >= 1
 clique505: + x45 + x71 >= 1
 clique506: + x45 + x73 + x92 >= 2
 clique507: + x45 + x78 + x85 >= 2
 clique508: + x45 + x82 >= 1
 clique509: + x45 + x84 >= 1
 clique510: + x45 + x96 >= 1
 clique511: + x46 + x52 + x75 >= 2
 clique512: + x46 + x60 + x66 >= 2
 clique513: + x46 + x62 + x72 >= 2
 clique514: + x46 + x69 + x73 >= 2
 clique515: + x46 + x74 + x81 >= 2
 clique516: + x46 + x77 >= 1
 clique517: + x46 + x79 >= 1
 clique518: + x46 + x82 + x87 >= 2
 clique519: + x46 + x86 >= 1
 clique520: + x46 + x92 >= 1
 clique521: + x46 + x99 >= 1
 clique522: + x47 + x79 >= 1
 clique523: + x47 + x96 >= 1
 clique524: + x48 + x52 >= 1
 clique525: + x48 + x67 >= 1
 clique526: + x48 + x79 >= 1
 clique527: + x48 + x96 + x97 >= 2
 clique528: + x49 + x59 + x99 >= 2
 clique529: + x49 + x70 + x75 >= 2
 clique530: + x49 + x74 >= 1
 clique531: + x49 + x76 >= 1
 clique532: + x49 + x78 >= 1
 clique533: + x49 + x85 + x87 >= 2
 clique534: + x49 + x90 >= 1
 clique535: + x50 + x61 + x87 >= 2
 clique536: + x50 + x95 >= 1
 clique537: + x50 + x97 >= 1
 clique538: + x51 + x81 >= 1
 clique539: + x51 + x87 >= 1
 clique540: + x51 + x92 >= 1
 clique541: + x52 + x53 + x70 >= 2
 clique542: + x52 + x54 + x99 >= 2
 clique543: + x52 + x63 >= 1
 clique544: + x52 + x71 >= 1
 clique545: + x52 + x91 >= 1
 clique546: + x52 + x94 >= 1
 clique547: + x52 + x98 >= 1
 clique548: + x53 + x56 + x80 >= 2
 clique549: + x53 + x73 + x86 >= 2
 clique550: + x53 + x83 + x94 >= 2
 clique551: + x53 + x87 >= 1
 clique552: + x53 + x92 + x96 >= 2
 clique553: + x54 + x67 >= 1
 clique554: + x54 + x79 >= 1
 clique555: + x54 + x87 >= 1
 clique556: + x54 + x89 >= 1
 clique557: + x55 + x83 >= 1
 clique558: + x55 + x87 >= 1
 clique559: + x56 + x57 + x67 + x70 >= 3
 clique560: + x56 + x76 >= 1
 clique561: + x56 + x87 >= 1
 clique562: + x56 + x99 >= 1
 clique563: + x57 + x60 >= 1
 clique564: + x57 + x65 >= 1
 clique565: + x57 + x69 + x89 >= 2
 clique566: + x57 + x93 >= 1
 clique567: + x58 + x60 + x71 >= 2
 clique568: + x58 + x75 >= 1
 clique569: + x58 + x83 >= 1
 clique570: + x59 + x79 + x80 >= 2
 clique571: + x59 + x84 >= 1
 clique572: + x60 + x61 + x85 >= 2
 clique573: + x60 + x73 >= 1
 clique574: + x60 + x77 + x91 >= 2
 clique575: + x60 + x79 >= 1
 clique576: + x60 + x80 + x94 >= 2
 clique577: + x60 + x82 + x92 >= 2
 clique578: + x60 + x86 >= 1
 clique579: + x60 + x97 >= 1
 clique580: + x61 + x62 + x68 >= 2
 clique581: + x61 + x64 + x83 >= 2
 clique582: + x61 + x70 + x86 >= 2
 clique583: + x61 + x84 >= 1
 clique584: + x61 + x92 >= 1
 clique585: + x61 + x98 >= 1
 clique586: + x61 + x99 >= 1
 clique587: + x62 + x66 + x81 >= 2
 clique588: + x62 + x92 >= 1
 clique589: + x63 + x87 >= 1
 clique590: + x63 + x88 + x97 >= 2
 clique591: + x64 + x77 >= 1
 clique592: + x64 + x85 >= 1
 clique593: + x64 + x93 >= 1
 clique594: + x64 + x94 >= 1
 clique595: + x64 + x97 >= 1
 clique596: + x65 + x70 >= 1
 clique597: + x65 + x85 + x88 >= 2
 clique598: + x65 + x92 >= 1
 clique599: + x65 + x95 >= 1
 clique600: + x65 + x98 >= 1
 clique601: + x66 + x67 >= 1
 clique602: + x66 + x83 >= 1
 clique603: + x66 + x97 >= 1
 clique604: + x67 + x72 >= 1
 clique605: + x67 + x78 >= 1
 clique606: + x67 + x92 >= 1
 clique607: + x67 + x98 >= 1
 clique608: + x68 + x80 >= 1
 clique609: + x69 + x80 >= 1
 clique610: + x69 + x91 >= 1
 clique611: + x69 + x95 >= 1
 clique612: + x70 + x76 >= 1
 clique613: + x70 + x81 >= 1
 clique614: + x70 + x90 >= 1
 clique615: + x70 + x93 >= 1
 clique616: + x70 + x99 >= 1
 clique617: + x71 + x97 >= 1
 clique618: + x72 + x89 >= 1
 clique619: + x73 + x75 >= 1
 clique620: + x73 + x90 >= 1
 clique621: + x74 + x94 >= 1
 clique622: + x75 + x77 >= 1
 clique623: + x75 + x80 + x97 >= 2
 clique624: + x75 + x86 >= 1
 clique625: + x75 + x87 >= 1
 clique626: + x75 + x92 >= 1
 clique627: + x76 + x80 >= 1
 clique628: + x77 + x95 >= 1
 clique629: + x78 + x86 >= 1
 clique630: + x79 + x88 >= 1
 clique631: + x79 + x91 >= 1
 clique632: + x80 + x81 + x98 >= 2
 clique633: + x80 + x96 >= 1
 clique634: + x81 + x82 >= 1
 clique635: + x82 + x88 >= 1
 clique636: + x82 + x89 >= 1
 clique637: + x85 + x96 + x99 >= 2
 clique638: + x87 + x98 >= 1
 clique639: + x89 + x90 >= 1
 clique640: + x89 + x95 >= 1
 clique641: + x89 + x96 >= 1
 clique642: + x90 + x92 >= 1
 clique643: + x92 + x97 >= 1
 clique644: + x93 + x95 >= 1

Bounds
 0 <= x0 <= 1
 0 <= x1 <= 1
 0 <= x2 <= 1
 0 <= x3 <= 1
 0 <= x4 <= 1
 0 <= x5 <= 1
 0 <= x6 <= 1
 0 <= x7 <= 1
 0 <= x8 <= 1
 0 <= x9 <= 1
 0 <= x10 <= 1
 0 <= x11 <= 1
 0 <= x12 <= 1
 0 <= x13 <= 1
 0 <= x14 <= 1
 0 <= x15 <= 1
 0 <= x16 <= 1
 0 <= x17 <= 1
 0 <= x18 <= 1
 0 <= x19 <= 1
 0 <= x20 <= 1
 0 <= x21 <= 1
 0 <= x22 <= 1
 0 <= x23 <= 1
 0 <= x24 <= 1
 0 <= x25 <= 1
 0 <= x26 <= 1
 0 <= x27 <= 1
 0 <= x28 <= 1
 0 <= x29 <= 1
 0 <= x30 <= 1
 0 <= x31 <= 1
 0 <= x32 <= 1
 0 <= x33 <= 1
 0 <= x34 <= 1
 0 <= x35 <= 1
 0 <= x36 <= 1
 0 <= x37 <= 1
 0 <= x38 <= 1
 0 <= x39 <= 1
 0 <= x40 <= 1
 0 <= x41 <= 1
 0 <= x42 <= 1
 0 <= x43 <= 1
 0 <= x44 <= 1
 0 <= x45 <= 1
 0 <= x46 <= 1
 0 <= x47 <= 1
 0 <= x48 <= 1
 0 <= x49 <= 1
 0 <= x50 <= 1
 0 <= x51 <= 1
 0 <= x52 <= 1
 0 <= x53 <= 1
 0 <= x54 <= 1
 0 <= x55 <= 1
 0 <= x56 <= 1
 0 <= x57 <= 1
 0 <= x58 <= 1
 0 <= x59 <= 1
 0 <= x60 <= 1
 0 <= x61 <= 1
 0 <= x62 <= 1
 0 <= x63 <= 1
 0 <= x64 <= 1
 0 <= x65 <= 1
 0 <= x66 <= 1
 0 <= x67 <= 1
 0 <= x68 <= 1
 0 <= x69 <= 1
 0 <= x70 <= 1
 0 <= x71 <= 1
 0 <= x72 <= 1
 0 <= x73 <= 1
 0 <= x74 <= 1
 0 <= x75 <= 1
 0 <= x76 <= 1
 0 <= x77 <= 1
 0 <= x78 <= 1
 0 <= x79 <= 1
 0 <= x80 <= 1
 0 <= x81 <= 1
 0 <= x82 <= 1
 0 <= x83 <= 1
 0 <= x84 <= 1
 0 <= x85 <= 1
 0 <= x86 <= 1
 0 <= x87 <= 1
 0 <= x88 <= 1
 0 <= x89 <= 1
 0 <= x90 <= 1
 0 <= x91 <= 1
 0 <= x92 <= 1
 0 <= x93 <= 1
 0 <= x94 <= 1
 0 <= x95 <= 1
 0 <= x96 <= 1
 0 <= x97 <= 1
 0 <= x98 <= 1
 0 <= x99 <= 1

Generals
 x0
 x1
 x2
 x3
 x4
 x5
 x6
 x7
 x8
 x9
 x10
 x11
 x12
 x13
 x14
 x15
 x16
 x17
 x18
 x19
 x20
 x21
 x22
 x23
 x24
 x25
 x26
 x27
 x28
 x29
 x30
 x31
 x32
 x33
 x34
 x35
 x36
 x37
 x38
 x39
 x40
 x41
 x42
 x43
 x44
 x45
 x46
 x47
 x48
 x49
 x50
 x51
 x52
 x53
 x54
 x55
 x56
 x57
 x58
 x59
 x60
 x61
 x62
 x63
 x64
 x65
 x66
 x67
 x68
 x69
 x70
 x71
 x72
 x73
 x74
 x75
 x76
 x77
 x78
 x79
 x80
 x81
 x82
 x83
 x84
 x85
 x86
 x87
 x88
 x89
 x90
 x91
 x92
 x93
 x94
 x95
 x96
 x97
 x98
 x99

End
