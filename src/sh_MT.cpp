// -*- C++ -*-
/*!
 * @file  sh_MT.cpp
 * @brief ModuleDescription
 * @date $Date$
 *
 * $Id$
 */

#include "sh_MT.h"

// Module specification
// <rtc-template block="module_spec">
static const char* sh_mt_spec[] =
  {
    "implementation_id", "sh_MT",
    "type_name",         "sh_MT",
    "description",       "ModuleDescription",
    "version",           "1.0.0",
    "vendor",            "VenderName",
    "category",          "Category",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
sh_MT::sh_MT(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_input1In("input1", m_input1),
    m_input2In("input2", m_input2),
    m_output1Out("output1", m_output1),
    m_output2Out("output2", m_output2)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
sh_MT::~sh_MT()
{
}



RTC::ReturnCode_t sh_MT::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("input1", m_input1In);
  addInPort("input2", m_input2In);
  
  // Set OutPort buffer
  addOutPort("output1", m_output1Out);
  addOutPort("output2", m_output2Out);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t sh_MT::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t sh_MT::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t sh_MT::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t sh_MT::onActivated(RTC::UniqueId ec_id)
{
	if(!shMTInitialize()){
		std::cerr << "ライブラリを初期化できません" << std::endl;
		return RTC::RTC_ERROR;
	}
	return RTC::RTC_OK;
}


RTC::ReturnCode_t sh_MT::onDeactivated(RTC::UniqueId ec_id)
{
	shMTTerminate();
	return RTC::RTC_OK;
}


RTC::ReturnCode_t sh_MT::onExecute(RTC::UniqueId ec_id)
{
	if(!m_input2In.isNew()){
		return RTC::RTC_OK;
	}
	m_input2In.read();
	
	//データの復元
	printf("データの復元_インデックスの読み込み(MT)\n");
	double c = m_input2.pop_length;//18522
	double d = m_input2.pop_width;//28
	printf("pop_x = %f	pop_y = %f	\n", c, d);//popのインデックス

	double a = m_input2.ind_length;//2
	double b = m_input2.ind_width;//4
	printf("ind_x = %f	ind_y = %f	\n", a, b);//indのインデックス
		
	printf("データの復元_popの読み込み(MT)\n");
	double test=0;
	int num = 0;

	mwArray pop_copy(18522, 28, mxDOUBLE_CLASS);//pop_copyの入れ物の型宣言
	///////////////////////////////////////////////////////////
	double *data_copy_pop = new double [m_input2.pop_length * m_input2.pop_width];
	
	for (num = 0; num < m_input2.pop_length * m_input2.pop_width ; num++) {
		data_copy_pop[num] = m_input2.pop[num];
	}

	pop_copy.SetData(data_copy_pop, m_input2.pop_length * m_input2.pop_width);//pop
	///////////////////////////////////////////////////////////

	printf("データの復元_indの読み込み(MT)\n");
		
	mwArray ind_copy(m_input2.ind_length, m_input2.ind_width, mxDOUBLE_CLASS);
	///////////////////////////////////////////////////////////
	double *data_copy_ind = new double [m_input2.pop_length * m_input2.pop_width];
	for (num = 0; num < m_input2.ind_length * m_input2.ind_width ; num++) {
		data_copy_ind[num] = m_input2.ind[num];
	}

	ind_copy.SetData(data_copy_ind, m_input2.ind_length * m_input2.ind_width);//ind
	///////////////////////////////////////////////////////////
		
	//pop,indの復元が終わったはず
	printf("復元完了(MT)\n");

	///////////////////////////////////////////////////////////
	//デフォルトパラメータの読み込み
	mwArray pars;
	shPars(1, pars);//デフォルトパラメータを.matから読み込みparsに入れる
	///////////////////////////////////////////////////////////

	///////////////////////////////////////////////////////////
	//SHmodel本体_MT

	//MT野の処理
	mwArray output(1, 2, mxCELL_CLASS);//出力の入れ物
		
	mwArray pop = pop_copy;
	mwArray ind = ind_copy;

	printf("モデル本体の処理開始(MT)\n");

	mwArray inputMT_a(1, 3, mxCELL_CLASS);//出力の入れ物
	inputMT_a.Get(1,1).Set(pop);//
	inputMT_a.Get(1,2).Set(ind);//
	inputMT_a.Get(1,3).Set(pars);//
	shModelMtLinear(2, output, inputMT_a);

	pop = output.Get(2, 1, 1); 
	ind = output.Get(2, 1, 2);
	printf("MT野の処理shModelMtLinear終了(MT)\n");

	mwArray inputMT_b(1, 3, mxCELL_CLASS);//出力の入れ物
	inputMT_b.Get(1,1).Set(pop);//
	inputMT_b.Get(1,2).Set(ind);//
	inputMT_b.Get(1,3).Set(pars);//
	shModelMtPreThresholdBlur(2, output, inputMT_b);

	pop = output.Get(2, 1, 1); 
	ind = output.Get(2, 1, 2);
	printf("MT野の処理shModelMtPreThresholdBlur終了(MT)\n");

	mwArray inputMT_c(1, 3, mxCELL_CLASS);//出力の入れ物
	inputMT_c.Get(1,1).Set(pop);//
	inputMT_c.Get(1,2).Set(ind);//
	inputMT_c.Get(1,3).Set(pars);//
	shModelHalfWaveRectification(2, output, inputMT_c);

	pop = output.Get(2, 1, 1); 
	ind = output.Get(2, 1, 2);
	printf("MT野の処理shModelHalfWaveRectification終了(MT)\n");

	mwArray inputMT_d(1, 3, mxCELL_CLASS);//出力の入れ物
	inputMT_d.Get(1,1).Set(pop);//
	inputMT_d.Get(1,2).Set(ind);//
	inputMT_d.Get(1,3).Set(pars);//
	shModelMtPostThresholdBlur(2, output, inputMT_d);

	pop = output.Get(2, 1, 1); 
	ind = output.Get(2, 1, 2);
	printf("MT野の処理shModelMtPostThresholdBlur終了(MT)\n");

	mwArray inputMT_e(1, 3, mxCELL_CLASS);//出力の入れ物
	inputMT_e.Get(1,1).Set(pop);//
	inputMT_e.Get(1,2).Set(ind);//
	inputMT_e.Get(1,3).Set(pars);//

	mwArray outputMT(1, 4, mxCELL_CLASS);//出力の入れ物
	mwArray nume;
	mwArray deno;
	
	shModelMtNormalization(4, outputMT, inputMT_e);

	printf("MT野の処理shModelMtNormalization終了(MT)\n");

	//計算結果の表示(仮)
	a =0;

	//////////////////////////////////////////////////////////////
	printf("\npop(MT)\n");
	mwArray pop2(outputMT.Get(2, 1, 1));//popの確保(2, 1, 2)がind_outputMT
	printf("NumberOfDimensions(MT) : %d\n", pop2.NumberOfDimensions());

	mwArray pop2_dims = pop2.GetDimensions();
	int pop2_dim1 =  pop2_dims.Get(1, 1);//int型に変換する必要あり
	int pop2_dim2 =  pop2_dims.Get(1, 2);
	printf("1 : (MT)%d\n", pop2_dim1);//378
	printf("2 : (MT)%d\n", pop2_dim2);//19

	printf("NumberOfElements(MT) : %d\n", pop2.NumberOfElements());

	for(int y = 1; y <= pop2_dim2; y++) {
		for(int x = 1; x <= pop2_dim1; x++) {
			//縦長に保存されている
			a = pop2.Get((mwSize)2, x, y);//mwArrayの呼び出し
		}
	}
	printf("pop_last(MT) = %f\n", a);
	printf("\n");
	///////////////////////////////////////////////////////////////

	///////////////////////////////////////////////////////////////
	printf("ind(MT)\n");
	mwArray ind2(outputMT.Get(2, 1, 2));//indの確保_outputMT
	printf("NumberOfDimensions(MT) : %d\n", ind2.NumberOfDimensions());

	mwArray ind2_dims = ind2.GetDimensions();
	int ind2_dim1 =  ind2_dims.Get(1, 1);//int型に変換する必要あり
	int ind2_dim2 =  ind2_dims.Get(1, 2);
	printf("1 : (MT)%d\n", ind2_dim1);//378
	printf("2 : (MT)%d\n", ind2_dim2);//19

	printf("NumberOfElements(MT) : %d\n", ind2.NumberOfElements());

	for(int y = 1; y <= ind2_dim2; y++) {
		//printf("\n");
		for(int x = 1; x <= ind2_dim1; x++) {
			a = ind2.Get((mwSize)2, x, y);//mwArrayの呼び出し
			printf("%f ", a);	
		}
		printf("\n");
	}
	printf("\n");
	///////////////////////////////////////////////////////////////

	//出力部分
	m_output2.pop_length = pop2_dim1;/////////////////////
	m_output2.pop_width = pop2_dim2;/////////////////////////

	m_output2.pop.length(pop2_dim1 * pop2_dim2);//popの配列の確保
		
	num = 0;
	double *data_copy_pop2 = new double [pop2_dim1 * pop2_dim2];
	pop.GetData(data_copy_pop2, pop2_dim1 * pop2_dim2);

	for (num = 0; num < pop2_dim1 * pop2_dim2 ; num++) {
		m_output2.pop[num] = data_copy_pop2[num];
	}

	//ind_2*4/
	m_output2.ind_length = ind2_dim1;////////////////
	m_output2.ind_width = ind2_dim2;/////////////////

	m_output2.ind.length(ind2_dim1 * ind2_dim2);//popの配列の確保
		
	double *data_copy_ind2 = new double [ind2_dim1 * ind2_dim2];
	ind.GetData(data_copy_ind2, ind2_dim1 * ind2_dim2);

	for (num = 0; num < ind2_dim1 * ind2_dim2; num++) {
		m_output2.ind[num] = data_copy_ind2[num];
	}

	m_output2Out.write();//書き出し_異常発生の場合接続カット

	///////////////////////////////////////////////////////////////////////////////////////////////////////

	printf("MT_end\n");
	delete[] data_copy_pop;//data_copyのデリート
	delete[] data_copy_ind;
	
	return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t sh_MT::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t sh_MT::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t sh_MT::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t sh_MT::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t sh_MT::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void sh_MTInit(RTC::Manager* manager)
  {
    coil::Properties profile(sh_mt_spec);
    manager->registerFactory(profile,
                             RTC::Create<sh_MT>,
                             RTC::Delete<sh_MT>);
  }
  
};


