/**
 *****************************************************************************
 * @file    batCave_512.h
 * @brief   provides an impulse response of a cave converted to samples using octave
 *stm32f769i_discovery board
 * @author  Manuel Faatz
 * source: http://www.echothief.com/batcave/
 ******************************************************************************
 *
 */

#define N 512

static float h[512] = {
    0.00000000f,  -0.00040347f, -0.00021504f, 0.00222780f,  0.00465901f,
    0.00422364f,  -0.00401016f, -0.00806695f, -0.00946391f, 0.00875342f,
    0.01488653f,  -0.02132857f, -0.21653444f, -0.40644517f, -0.20124492f,
    0.15037413f,  0.19149171f,  -0.21836743f, -0.74847834f, -0.96124278f,
    -0.76089521f, -0.38012879f, -0.22200916f, -0.31637291f, -0.45582236f,
    -0.49006706f, -0.38043719f, -0.25804921f, -0.18486819f, -0.12235845f,
    -0.10298953f, -0.06929684f, 0.03001843f,  0.13475135f,  0.21848498f,
    0.23864859f,  0.21792948f,  0.22479764f,  0.25948511f,  0.26826882f,
    0.25441695f,  0.26165033f,  0.26770482f,  0.26895916f,  0.29302811f,
    0.31296664f,  0.29768592f,  0.26228541f,  0.24874179f,  0.27032306f,
    0.30364659f,  0.31524173f,  0.27839406f,  0.22590868f,  0.19917728f,
    0.19616871f,  0.17416426f,  0.11906646f,  0.07441402f,  0.06411480f,
    0.06524036f,  0.06521972f,  0.07109728f,  0.07141794f,  0.07715962f,
    0.08968943f,  0.09236204f,  0.08373699f,  0.07973851f,  0.08569271f,
    0.08513056f,  0.07884964f,  0.06499175f,  0.05072845f,  0.04530071f,
    0.04861007f,  0.05289569f,  0.03743499f,  0.01355884f,  0.01818254f,
    0.05308229f,  0.07988900f,  0.07429646f,  0.04860746f,  0.04742603f,
    0.07718394f,  0.09776335f,  0.09100300f,  0.07156807f,  0.06465243f,
    0.06902205f,  0.08052815f,  0.09239878f,  0.09953916f,  0.10048697f,
    0.10035656f,  0.10568488f,  0.11338804f,  0.12080456f,  0.11712638f,
    0.10859670f,  0.09790692f,  0.09500856f,  0.09924608f,  0.08483977f,
    0.06041499f,  0.04192684f,  0.03341966f,  0.03609433f,  0.02373438f,
    0.00060096f,  -0.01898131f, -0.03170902f, -0.02810891f, -0.02789813f,
    -0.03239116f, -0.03524935f, -0.03342042f, -0.03052180f, -0.02556101f,
    -0.02344076f, -0.01457148f, -0.00154252f, 0.00585303f,  0.02727884f,
    0.02460491f,  -0.02333033f, -0.07948358f, -0.01824488f, 0.10553370f,
    0.05223577f,  -0.09859601f, -0.17313557f, -0.22510990f, -0.28791292f,
    -0.28230413f, -0.21584977f, -0.15665059f, -0.15059177f, -0.15891757f,
    -0.17032460f, -0.24805565f, -0.28837356f, -0.32231562f, -0.37373244f,
    -0.28383792f, -0.13481114f, -0.04305662f, -0.03969394f, -0.06659964f,
    -0.01437344f, 0.09009587f,  0.11375844f,  0.03083129f,  -0.03315122f,
    -0.04528789f, 0.01819857f,  0.06815664f,  0.08297590f,  0.14394742f,
    0.19056988f,  0.19589563f,  0.15360129f,  0.13411205f,  0.12190967f,
    0.03490520f,  -0.09922077f, -0.16373308f, -0.09965434f, 0.02861262f,
    0.09102474f,  -0.01137741f, -0.14604405f, -0.19038980f, -0.12507089f,
    0.01266743f,  0.04109101f,  -0.11493511f, -0.25581082f, -0.26493612f,
    -0.22439553f, -0.18268286f, -0.05344794f, 0.12018580f,  0.07864133f,
    -0.15172336f, -0.31665035f, -0.29585732f, -0.16358872f, -0.05845816f,
    -0.01986551f, -0.01755780f, 0.02228868f,  0.07857667f,  0.07026651f,
    0.12218716f,  0.22823432f,  0.21032716f,  0.14704626f,  0.14185690f,
    0.20118454f,  0.20324464f,  0.04146228f,  -0.09467376f, -0.09424672f,
    -0.00167012f, 0.12751789f,  0.21424861f,  0.26862091f,  0.26204387f,
    0.18716109f,  0.14734908f,  0.16720886f,  0.19397978f,  0.18161092f,
    0.13012915f,  0.10504477f,  0.16394817f,  0.24418332f,  0.27745786f,
    0.26178387f,  0.18886739f,  0.05307620f,  -0.05709515f, -0.05997080f,
    -0.00464482f, 0.06591720f,  0.10116974f,  0.10546289f,  0.10105291f,
    0.09643711f,  0.10328537f,  0.09806797f,  0.06411700f,  -0.02121103f,
    -0.10801108f, -0.09584845f, -0.01366226f, -0.01557520f, -0.10660969f,
    -0.16757810f, -0.14672012f, -0.12180015f, -0.09464317f, -0.02906471f,
    -0.00425060f, -0.02416010f, -0.00236125f, 0.03838031f,  -0.05556470f,
    -0.20018504f, -0.22202902f, -0.15498873f, -0.18126634f, -0.28065232f,
    -0.26306375f, -0.19859668f, -0.14461167f, -0.06779975f, -0.00835654f,
    -0.00262453f, -0.03635680f, -0.11409083f, -0.20694535f, -0.18948929f,
    -0.06919512f, -0.01198142f, -0.09608021f, -0.16934234f, -0.14193686f,
    -0.09898894f, -0.02230944f, 0.03617871f,  -0.01470637f, -0.08124523f,
    -0.07782093f, -0.00094149f, 0.05677849f,  0.02932140f,  -0.01794671f,
    -0.06647704f, -0.09276712f, -0.06821614f, -0.07308692f, -0.09957409f,
    -0.07056929f, -0.00334806f, 0.06060333f,  0.05709531f,  -0.02029638f,
    -0.06374887f, -0.02726153f, 0.01890274f,  0.00001742f,  -0.07366870f,
    -0.10953025f, -0.07457305f, -0.01320844f, 0.03665354f,  -0.00845191f,
    -0.08871825f, -0.05576385f, -0.00168590f, -0.01950961f, -0.06225280f,
    -0.07695802f, -0.07462406f, -0.07401281f, 0.01886729f,  0.16152210f,
    0.17615698f,  0.03994122f,  -0.07270256f, -0.01904553f, 0.06385444f,
    0.03267666f,  -0.04426614f, -0.04275859f, -0.00277529f, -0.01596589f,
    0.02346468f,  0.08560990f,  0.04951984f,  -0.05758438f, -0.11945241f,
    -0.04685909f, 0.01732391f,  -0.00453919f, -0.05077934f, -0.06879421f,
    -0.07026150f, -0.06789758f, -0.01768292f, 0.00659548f,  -0.02503203f,
    -0.08325774f, -0.06392155f, 0.05077138f,  0.06785957f,  -0.03187026f,
    -0.10146276f, -0.04832443f, 0.05604086f,  0.08849843f,  0.02651028f,
    -0.05823992f, -0.06070557f, 0.02236349f,  0.09451226f,  0.07059334f,
    0.01556514f,  0.01592995f,  0.03527769f,  0.05562344f,  0.07404091f,
    0.09458089f,  0.09531995f,  0.03701763f,  -0.01880816f, -0.03396623f,
    -0.01861760f, 0.01375228f,  0.02375177f,  0.00488499f,  -0.03500405f,
    -0.08517026f, -0.11614732f, -0.09221798f, -0.06696785f, -0.05372027f,
    -0.00403445f, -0.03681193f, -0.15059772f, -0.17980804f, -0.09042757f,
    0.01509615f,  0.00202236f,  -0.07286831f, -0.04524004f, 0.07899183f,
    0.20561359f,  0.27048569f,  0.25971998f,  0.21356388f,  0.13046643f,
    0.03824280f,  0.00934061f,  0.03637967f,  0.05221714f,  0.02630584f,
    0.03211049f,  0.04355052f,  -0.00149570f, -0.04229585f, -0.05486634f,
    -0.03766636f, -0.00112773f, 0.01686541f,  0.00200630f,  -0.03863438f,
    -0.11436171f, -0.18833232f, -0.18005774f, -0.08926764f, -0.02642149f,
    -0.06691066f, -0.13831972f, -0.11791985f, -0.02725051f, -0.02170257f,
    -0.10698219f, -0.10777965f, 0.01246358f,  0.01506207f,  -0.12735369f,
    -0.21700803f, -0.17695990f, -0.07202615f, -0.08325847f, -0.11364632f,
    -0.01577567f, 0.01027638f,  -0.10510171f, -0.18066447f, -0.10838464f,
    0.00386554f,  -0.02061789f, -0.10039177f, -0.13284611f, -0.14603166f,
    -0.15974651f, -0.12696903f, -0.00555735f, 0.03581884f,  -0.03020196f,
    -0.03844622f, 0.02237838f,  0.02993554f,  -0.01258179f, 0.02036670f,
    0.01302065f,  0.17831432f,  0.08803674f,  0.00871686f,  -0.02744832f,
    -0.00965325f, 0.05962626f,  0.04025558f,  0.02030855f,  0.02228361f,
    -0.02402485f, -0.04531788f, -0.04496737f, -0.00557141f, 0.04267497f,
    -0.00516061f, -0.10034390f, -0.09694903f, 0.01039366f,  0.08259344f,
    0.11447811f,  0.17919344f,  0.21318454f,  0.12967212f,  -0.02521429f,
    -0.10429488f, 0.01518894f,  0.22002922f,  0.27013764f,  0.14875942f,
    0.01642890f,  0.02647619f,  0.12959112f,  0.16621325f,  0.08980281f,
    -0.00309745f, -0.02487200f, -0.08646004f, -0.08150355f, 0.05026962f,
    0.12268770f,  0.15492090f,  0.11987703f,  0.05868178f,  0.09219202f,
    0.16782294f,  0.20385602f,  0.18339211f,  0.13194307f,  0.09053368f,
    0.10094377f,  0.13876487f,  0.10990567f,  -0.01739586f, -0.10200144f,
    -0.09351404f, -0.14985234f, -0.26464179f, -0.28254739f, -0.16288222f,
    0.01253205f,  0.08071794f,  0.08303621f,  0.06087564f,  -0.01235412f,
    -0.03048536f, -0.01556587f, -0.00204730f, -0.03717908f, -0.09854914f,
    -0.05096157f, 0.07260061f};
