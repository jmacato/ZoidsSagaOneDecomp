#include "types.h"

struct CgbChannel
{
    u8 status_flags;
    u8 type;
    u8 right_volume;
    u8 left_volume;
    u8 attack;
    u8 decay;
    u8 sustain;
    u8 release;
    u8 key;
    u8 envelope_volume;
    u8 envelope_goal;
    u8 envelope_counter;
    u8 pseudo_echo_volume;
    u8 pseudo_echo_length;
    u8 dummy1;
    u8 dummy2;
    u8 gate_time;
    u8 midi_key;
    u8 velocity;
    u8 priority;
    u8 rhythm_pan;
    u8 dummy3[3];
    u8 dummy5;
    u8 sustain_goal;
    u8 n4;
    u8 pan;
    u8 pan_mask;
};

static inline int cgb_pan(struct CgbChannel *chan)
{
    u32 right_volume = chan->right_volume;
    u32 left_volume = chan->left_volume;

    if ((right_volume = (u8)right_volume) >= (left_volume = (u8)left_volume))
    {
        if (right_volume / 2 >= left_volume)
        {
            chan->pan = 0x0F;
            return 1;
        }
    }
    else
    {
        if (left_volume / 2 >= right_volume)
        {
            chan->pan = 0xF0;
            return 1;
        }
    }

    return 0;
}

void func_0805C724(struct CgbChannel *chan)
{
    if (!cgb_pan(chan))
    {
        chan->pan = 0xFF;
        chan->envelope_goal = (u32)(chan->right_volume + chan->left_volume) >> 4;
    }
    else
    {
        chan->envelope_goal = (u32)(chan->right_volume + chan->left_volume) >> 4;
        if (chan->envelope_goal > 15)
            chan->envelope_goal = 15;
    }

    chan->sustain_goal = (chan->envelope_goal * chan->sustain + 15) >> 4;
    chan->pan &= chan->pan_mask;
}
