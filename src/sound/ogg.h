#ifndef __ogg_h__
#define __ogg_h__

#include <string>
#include <iostream>
using namespace std;

#include <al/al.h>
#include <ogg/ogg.h>
#include <vorbis/vorbisfile.h>
#include "log4cxx/logger.h"


#define BUFFER_SIZE (4096 * 4)
#define BUFFERS 20


class ogg_stream
{
    public:

        void open(string path);
        void release();
        void display();
        bool playback();
        bool playing();
        bool update();

    protected:

        bool stream(ALuint buffer);
        void empty();
        void check();
        string errorString(int code);

    private:

        FILE*           oggFile;
        OggVorbis_File  oggStream;
        vorbis_info*    vorbisInfo;
        vorbis_comment* vorbisComment;

        ALuint buffers[BUFFERS];
        ALuint source;
        ALenum format;
};


#endif // __ogg_h__
