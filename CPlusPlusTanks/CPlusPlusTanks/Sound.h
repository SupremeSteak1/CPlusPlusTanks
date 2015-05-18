# pragma once

# include < string >
# include < iostream >
# include < fstream >

# include " ../OpenAL1.1SDK/include/al.h"

using namespace std ;

 struct FMTCHUNK 
 {
	 short format;
	 short channels;
	 unsigned long srate;
	 unsigned long bps;
	 short balign;
	 short samp;
 };class Sound {
	friend class SoundManager ;
public :
	char * GetData () { return data ;}
	int GetBitRate () { return bitRate ;}
	float GetFrequency () { return freqRate ;}
	int GetChannels () { return channels ;}
	int GetSize () { return size ;}
	ALuint GetBuffer () { return buffer ;}

	ALenum GetOALFormat ();
	float GetLength ();

protected :
	Sound ();
	~ Sound ( void );

	void LoadFromWAV ( string filename );
	void LoadWAVChunkInfo ( ifstream & file , string & name ,
	unsigned int & size );

	char * data ;

	float length ;
	int bitRate ;
	float freqRate ;
	int size ;
	int channels ;

	ALuint buffer ;
};