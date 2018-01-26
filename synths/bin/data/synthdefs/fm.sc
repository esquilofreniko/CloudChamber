s.boot;

(
SynthDef(\fm, {
    arg cfreq = 100, mratio = 0.7, mindex = 100, amp = 0.5, pan = 0, decay = 8;
    var carrier, modulator, amp_env;
    amp_env = EnvGen.ar(Env([0, 1, 1, 0], [0.01, 0.1, decay]), doneAction:2);
    modulator = SinOsc.ar(cfreq * mratio, 0, mindex + rrand(50, 100));
    carrier = SinOsc.ar(cfreq + modulator, 0, amp * amp_env);
    Out.ar(0, Pan2.ar(carrier, pan));
}).store;
)


