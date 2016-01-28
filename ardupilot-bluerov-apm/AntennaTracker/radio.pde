// -*- tab-width: 4; Mode: C++; c-basic-offset: 4; indent-tabs-mode: nil -*-

// Functions to read the RC radio input

static void read_radio()
{
    if (hal.rcin->new_input()) {
        channel_yaw.set_pwm(hal.rcin->read(CH_YAW));
        channel_pitch.set_pwm(hal.rcin->read(CH_PITCH));
    }
}
