static const u16 motos_anim_motos_carry_start_values[] = {
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
	0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x0000, 
	0xFFFF, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0xFFFF, 
	0xFFFF, 0x0000, 0x0000, 0xFFFF, 0x0000, 0x0000, 0xD1A4, 0x0000, 0x0000, 
	0xAFAA, 0x0000, 0x0000, 0xFFFF, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 
	0x0000, 0x0000, 0xFFFF, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 
	0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 
	0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0xFFFF, 0x0000, 
	0x00BB, 0x02D8, 0x0643, 0x0AF3, 0x10DF, 0x17F8, 0x2023, 0x2931, 0x32DD, 
	0x3CD6, 0x46C8, 0x506C, 0x5994, 0x622A, 0x6A31, 0x71BE, 0x78F4, 0x8000, 
	0x870C, 0x8E18, 0x951C, 0x9C15, 0xA308, 0xAA03, 0xB118, 0xB861, 0xBFFF, 
	0xC813, 0xD08B, 0xD935, 0xE1C4, 0xE9DD, 0xF124, 0xF742, 0xFBF1, 0xFEF0, 
	0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 
	0xFFFF, 0xFFFF, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 
	0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 
	0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 
};

static const u16 motos_anim_motos_carry_start_indices[] = {
	0x0001, 0x0000, 0x0001, 0x0001, 0x0001, 0x0002, 0x0001, 0x0003, 0x0001, 
	0x0004, 0x0001, 0x0005, 0x0001, 0x0006, 0x0001, 0x0007, 0x0001, 0x0008, 
	0x0001, 0x0009, 0x0001, 0x000A, 0x0001, 0x000B, 0x0001, 0x000C, 0x0001, 
	0x000D, 0x0001, 0x000E, 0x0001, 0x000F, 0x0001, 0x0010, 0x0001, 0x0011, 
	0x0001, 0x0012, 0x0001, 0x0013, 0x0001, 0x0014, 0x0001, 0x0015, 0x0001, 
	0x0016, 0x0001, 0x0017, 0x0001, 0x0018, 0x0001, 0x0019, 0x0001, 0x001A, 
	0x0001, 0x001B, 0x0001, 0x001C, 0x0001, 0x001D, 0x0001, 0x001E, 0x0001, 
	0x001F, 0x0001, 0x0020, 0x0001, 0x0021, 0x0001, 0x0022, 0x0001, 0x0023, 
	0x0001, 0x0024, 0x0001, 0x0025, 0x0001, 0x0026, 0x0001, 0x0027, 0x0001, 
	0x0028, 0x0001, 0x0029, 0x0001, 0x002A, 0x0001, 0x002B, 0x0001, 0x002C, 
	0x0001, 0x002D, 0x0001, 0x002E, 0x0001, 0x002F, 0x0001, 0x0030, 0x0001, 
	0x0031, 0x0001, 0x0032, 0x001D, 0x0033, 0x0025, 0x0050, 0x0020, 0x0075, 
	
};

static const struct Animation motos_anim_motos_carry_start = {
	1,
	0,
	0,
	0,
	36,
	ANIMINDEX_NUMPARTS(motos_anim_motos_carry_start_indices),
	motos_anim_motos_carry_start_values,
	motos_anim_motos_carry_start_indices,
	0,
};
