import { FC, useEffect} from "react";
import { CHAINS_ } from "../../constants";
import ParallaxTiltEffect from './TiltCard';


export const ParallaxCard:FC<any> = (props:any) => {

	useEffect( () => {
		var Tiles:any = [];

		var trk: boolean = false;
		for ( let i = 0 ; i < Object.keys(CHAINS_).length; i++ ){
			Tiles.push( ParallaxWraper((CHAINS_ as any)[Object.keys(CHAINS_)[i]].id , i , !trk) )
			trk = !trk;
		}
	}, []);

	function ParallaxWraper( _wrapChain: any , _wrapNum:any , _tileTilt:boolean ) {
		return new ParallaxTiltEffect(
		 document.querySelector(`.wrap--${_wrapNum}`),_tileTilt ? 'normal' : 'reverse',_wrapChain);
	}

	function createSubSection( itm:string, idx:number ) {
		var ch = (CHAINS_ as any)[itm];
 		return (
 			<div className={`wrap wrap--${idx}`} key={idx}>
		    	<div className={`container container--${idx}}`} >
			    	<div className="parallaxContain">
						<h1>{ch.name}</h1>
						<h3><span>For&nbsp;&nbsp;</span>{ch.features[0]}</h3>
						<img src={ch.logo} alt={ch.name}/>
						<div>
							<h5>chainId: {ch.id}</h5>
						</div>
			    	</div>
		    	</div>
	  		</div>
	  	)
	}

	return(
		<section className="main">
		{
			Object.keys(CHAINS_).map((itm:any , idx:any) => createSubSection( itm, idx ) )
		}
		</section>
	)

}
