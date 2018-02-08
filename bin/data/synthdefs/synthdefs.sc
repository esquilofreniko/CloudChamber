s.reboot;

(
SynthDef(\fm_melody, {
    arg cfreq = 100, mratio = 0.7, mindex = 100, amp = 0.5, pan = 0, decay = 8;
    var carrier, modulator, amp_env;
    amp_env = EnvGen.ar(Env([0, 1, 1, 0], [0.01, 0.1, decay]), doneAction:2);
    modulator = SinOsc.ar(cfreq * mratio, 0, mindex + rrand(50, 100));
    carrier = SinOsc.ar(cfreq + modulator, 0, amp * amp_env);
    Out.ar(0, Pan2.ar(carrier, pan));
}).store;
)

(
SynthDef(\sine_drone, {
	arg freq = 100, amp = 0.5, pan = 0, attack = 1, decay = 1;
	var osc, amp_env;
	amp_env = EnvGen.ar(Env([0, 1, 1, 0], [attack, 0.1, decay]), doneAction:2);
	osc = SinOsc.ar(freq, 0, amp_env);
	Out.ar(0, Pan2.ar(osc, pan));
}).store;
)

(
SynthDef(\fmhat, {
	arg dec=0.05,moddec=0.25,maxfreq=200,maxfm=800,amp=0.25,reverb=0;
	var sig,harmon,modind,modenv,ampenv,freq,fm,close;
	modenv = EnvGen.kr(Env([1,0],[moddec]),doneAction:2);
	ampenv = EnvGen.kr(Env([1,0],[dec]));
	freq = Rand(0,maxfreq);
	fm = Rand(100,maxfm);
	harmon = freq*fm;
	modind = harmon * modenv;
	harmon = (SinOsc.ar(harmon)*modind);
	sig = freq + harmon;
	sig = SinOsc.ar(sig);
	sig = FreeVerb.ar(sig,reverb,0.5,0.5);
	sig = sig*ampenv*amp;
	Out.ar(0,sig);
	Out.ar(1,sig);
}).store
)

Synth(\fmhat);