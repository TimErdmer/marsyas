/*
 ** Copyright (C) 1998-2006 George Tzanetakis <gtzan@cs.uvic.ca>
 **  
 ** This program is free software; you can redistribute it and/or modify
 ** it under the terms of the GNU General Public License as published by
 ** the Free Software Foundation; either version 2 of the License, or
 ** (at your option) any later version.
 ** 
 ** This program is distributed in the hope that it will be useful,
 ** but WITHOUT ANY WARRANTY; without even the implied warranty of
 ** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 ** GNU General Public License for more details.
 ** 
 ** You should have received a copy of the GNU General Public License
 ** along with this program; if not, write to the Free Software 
 ** Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

/** 
  \class MidiInput
  \brief Update midi inpput using controls. Just through for dataflow. 
 */

#ifndef MARSYAS_MIDIINPUT_H
#define MARSYAS_MIDIINPUT_H

#include "MarSystem.h"	

#ifdef MARSYAS_MIDIIO
#include "RtMidi.h"
#endif 

namespace Marsyas
{

    class MidiInput: public MarSystem
    {
        private: 
            void myUpdate(MarControlPtr sender);
            void addControls();
            static void mycallback(double deltatime, std::vector< unsigned char> * message, void *userData);

#ifdef MARSYAS_MIDIIO
            RtMidiIn* midiin;
#endif 
            int byte3, byte2, type;  
            bool initMidi;
            bool virtualPort;
        public:
            MidiInput(std::string name);
            ~MidiInput();
            MarSystem* clone() const;  

            int rval;

            void myProcess(realvec& in, realvec& out);
    };

}//namespace Marsyas

#endif
