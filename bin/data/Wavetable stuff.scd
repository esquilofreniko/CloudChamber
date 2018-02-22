x = Buffer.alloc(s, 512, 1);
(
a = Array.fill(512,{rrand(-100,100)*0.01});
512.do({arg i; x.set(i,a[i]);i=i+1});
x.plot;
)

(
SynthDef("WTX",{arg a;
	a = Array.fill(512,{arg i; rrand(-100,100)*0.01});
	512.do({arg i; x.set(i,a[i]);i=i+1});
	x.plot;
}).store;
)

x.plot

x.bufnum;
z = Osc.ar(x.bufnum,4400,1,0);
z.play;


Wavetable.sineFill(512, 1.0/a).plot;
Wavetable.sineFill(512, [1]).plot("Table 1", Rect(50, 50, 150, 450));

(
SynthDef("help-Osc",{ arg out=0,bufnum=0;
	Out.ar(out,
		Osc.ar(bufnum,
			Osc.ar(bufnum,
			4400),
			0,
			0.25)
	)
}).play(s,[\out, 0, \bufnum, x.bufnum]);
)