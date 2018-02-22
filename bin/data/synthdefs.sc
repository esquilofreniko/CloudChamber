s.reboot;

(
SynthDef(\sine_drone, {
	arg freq = 100, amp = 1, mratio = 0.5, mindex = 500, pan = 0, attack = 1, decay = 4, mix = 1, room = 0.5, damp = 0.5;
	var carrier, modulator, amp_env, output;
	amp_env = EnvGen.ar(Env([0, 1, 1, 0], [attack, 0.1, decay]), doneAction:2);
	modulator = SinOsc.ar(freq * mratio, 0, mindex);
	carrier = SinOsc.ar(freq + modulator, 0, amp_env);
	output = Pan2.ar(FreeVerb.ar(carrier, mix, room, damp, amp), pan);
	Out.ar(0, output);
}).store;
)

(
SynthDef(\wavetable, {
	arg
}