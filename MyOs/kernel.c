/*
*
* kernel.c - version Lwla ga3
*
*/

#define WHITE_TXT 0X07 /* light gray on black text */

void k_clear_screen();
unsigned int k_printf(char *message, unsigned int line);

/* k_main: The kernel main function */
void k_main()
{
	k_clear_screen();
	k_printf("Hello, This is My First Simple Kernel Ever", 0);
}

/* k_clear_screen: to clear the entire text screen */
void k_clear_screen()
{
	char *vidmem = (char *) 0xb8000;
	unsigned int i;

	i = 0;
	while (i < (80*25*2))
	{
		vidmem[i] = 32;
		i++;
		vidmem[i]=WHITE_TXT;
		i++;
	}
}

unsigned int k_printf(char *message, unsigned int line)
{
	char *vidmem = (char *)0xb8000;
	unsigned int i;
	
	i = 0;
	i = (line * 80 * 2);

	while (*message != 0)
	{
		if (*message == '\n')
		{
			line++;
			i = (line * 80 * 2);
			*message++;
		}
		else
		{
			vidmem[i] = *message;
			*message++;
			i++;
			vidmem[i] = WHITE_TXT;
			i++;
		}
	}
	return (1);
}
