long nextcombits(long s){
	long lo=s&-s,r=s+lo;
	return(s&~r)/lo>>1|r;
	//s+lo:loから1が続く箇所を全消し、最初に0になったところを立てる
	//(s&-r)/lo>>1でsの中で(最初に連続1だった部分の個数-1)個の1を0-offsetで並べてrと結合
}
