#ifndef HP_PLAY_FILE_FLATTENED_22052018
#define HP_PLAY_FILE_FLATTENED_22052018

#include "HP_midifile.h"
#include <iostream>


// Abstract Play Monitor Class HP_PLAY_MONITOR
/*
class HP_PLAY_MONITOR
{
public:
	// takt/beat monitor
	virtual void HP_PlayTBMonitor(int takt, int beat) = 0;
	// chord monitor
	virtual void HP_PlayChMonitor(char* chord_text) = 0;
	// lyric monitor
	virtual void HP_PlayLyMonitor(char* lyric_text) = 0;
};
*/

class HP_PLAY_MONITOR_DELPHI : public HP_PLAY_MONITOR
{
public:
	// takt/beat monitor
	void HP_PlayTBMonitor(int takt, int beat) {
    std::cout << "void HP_PlayTBMonitor(int takt, int beat) has been called" << std::endl;
  }
  
	// chord monitor
	void HP_PlayChMonitor(char* chord_text) {
    std::cout << "void HP_PlayChMonitor(char* chord_text) has been called" << std::endl;
  }
  
	// lyric monitor
	void HP_PlayLyMonitor(char* lyric_text) {
    std::cout << "void HP_PlayLyMonitor(char* lyric_text) has been called" << std::endl;
  }
};


/*
 * “Flattening” the object
 * To “flatten” a class, you export a simple C++ function for each method
 */
 
// The first parameter of the functions (except for the “constructor” function) should be a pointer to the object.
typedef HP_PLAY_MONITOR_DELPHI * DELPHI_PTR;

// define a macro for the calling convention and export type
#define EXPORTCALL __declspec(dllexport) __stdcall

// constructor
DELPHI_PTR EXPORTCALL NewDelphiHp(void)
{
  return new HP_PLAY_MONITOR_DELPHI();
}

// destructor
void EXPORTCALL DeleteDelphiHp(DELPHI_PTR delphi_ptr)
{
  delete delphi_ptr;
}

// HP_PlayTBMonitor
void EXPORTCALL DELPHI_HP_PlayTBMonitor(DELPHI_PTR delphi_ptr, int takt, int beat)
{
  delphi_ptr->HP_PlayTBMonitor(int takt, int beat);
}

// HP_PlayChMonitor
void EXPORTCALL DELPHI_HP_PlayChMonitor(DELPHI_PTR delphi_ptr, char* chord_text)
{
  delphi_ptr->HP_PlayChMonitor(char* chord_text);
}

// HP_PlayLyMonitor
void EXPORTCALL DELPHI_HP_PlayLyMonitor(DELPHI_PTR delphi_ptr, char* lyric_text)
{
  delphi_ptr->HP_PlayLyMonitor(char* lyric_text);
}
  
#endif
