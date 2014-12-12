#include "stdafx.h"
#include "FormData.h"


CFormData::CFormData(void)
{
	m_strPostParam = "";
}


CFormData::~CFormData(void)
{
}

void CFormData::InitData()
{
	m_Fields["org.apache.struts.taglib.html.TOKEN"] = "";
	m_Fields["zyzRegistrationMode"] = "";
	m_Fields["zyzServiceTime"] = "";
	m_Fields["usableServiceTime"] = "";
	m_Fields["createUserId"] = "";
	m_Fields["zyzType"] = "";
	m_Fields["orginfoid"] = "";
	m_Fields["zyzNumber"] = "";
	m_Fields["zyzCertCode"] = "";
	m_Fields["zyzCnName"] = "";
	m_Fields["zyzEnName"] = "";
	m_Fields["zyzPapersType"] = "1717";//内地居民身份证
	m_Fields["zyzPapersNumber"] = "";
	m_Fields["zyzSex"] = "";
	m_Fields["zyzNation"] = "";
	m_Fields["zyzNationality"] = "1595";
	m_Fields["zyzPoliticsStatus"] = "";
	m_Fields["zyzBirthStr"] = "";
	m_Fields["zyzEducationLevel"] = "";
	m_Fields["zyzJob"] = "";
	m_Fields["zyzHealthStatus"] = "";
	m_Fields["china"] = "771427";
	m_Fields["serviceProvinceName"] = "重庆市";
	m_Fields["serviceProvince"] = "588702";
	m_Fields["serviceCityName"] = "重庆市";
	m_Fields["serviceCity"] = "785874";
	m_Fields["serviceCountyName"] = "巴南区";
	m_Fields["serviceCounty"] = "591677";
	m_Fields["serviceStreetName"] = "鱼洞街道";
	m_Fields["serviceStreet"] = "591678";
	m_Fields["serviceCommuntityName"] = "广益街社区居委会";
	m_Fields["serviceCommuntity"] = "591687";
	m_Fields["serviceDetail"] = "";
	m_Fields["provinceName"] = "重庆市";
	m_Fields["province"] = "588702";
	m_Fields["cityName"] = "重庆市";
	m_Fields["city"] = "785874";
	m_Fields["countyName"] = "巴南区";
	m_Fields["county"] = "591677";
	m_Fields["streetName"] = "鱼洞街道";
	m_Fields["street"] = "591678";
	m_Fields["communtityName"] = "广益街社区居委会";
	m_Fields["communtity"] = "591687";
	m_Fields["zyzAddressDetail"] = "";
	m_Fields["zyzFixed"] = "";
	m_Fields["zyzMobile"] = "";
	m_Fields["zyzEMail"] = "";
	m_Fields["zyzBloodType"] = "0";
	m_Fields["zyzQq"] = "";
	m_Fields["unitID"] = "5241";
	m_Fields["zyzEmergencyName"] = "";
	m_Fields["zyzEmergencySex"] = "0";
	m_Fields["zyzEmergencyBirthStr"] = "";
	m_Fields["zyzEmergencyRelation"] = "0";
	m_Fields["zyzEmergencyMobile"] = "";
	m_Fields["zyzWorkUnitName"] = "";
	m_Fields["zyzWorkUnitAddress"] = "";
	m_Fields["zyzWorkUnitMobile"] = "";
	m_Fields["zyzWorkUnitContact"] = "";
	m_Fields["zyzWorkSeniority"] = "";
	m_Fields["workTimeStr"] = "";
	m_Fields["schoolName"] = "";
	m_Fields["schoolAddress"] = "";
	m_Fields["schoolMobile"] = "";
	m_Fields["schoolContact"] = "";
	m_Fields["zyzUsername"] = "";
	m_Fields["zyzPassword"] = "123456";
	m_Fields["zyzIfHavedJoin"] = "0";
	m_Fields["zyzIfOfferVehicle"] = "0";
	m_Fields["zyzIfJoinOutland"] = "0";
	m_Fields["zyzServiceMode"] = "";
	m_Fields["show_zyzServiceMode"] = "";
	m_Fields["zyzSpecialty"] = "";
	m_Fields["show_zyzSpecialty"] = "";
	m_Fields["zyzServiceTarget"] = "";
	m_Fields["show_zyzServiceTarget"] = "";
	m_Fields["holidaysTimes"] = "";
	m_Fields["zyzCanServiceTime"] = "";
	m_Fields["show_zyzCanServiceTime"] = "";
	m_Fields["zyzServiceHistory"] = "";

	
	CODE_NAME codename;
	//初始化性别列表
	sprintf(codename.code, "%s", "119");
	sprintf(codename.name, "%s", "男");
	m_SexList.push_back(codename);

	sprintf(codename.code, "%s", "120");
	sprintf(codename.name, "%s", "女");
	m_SexList.push_back(codename);

	//初始化职业类型列表
	sprintf(codename.code, "%s", "5367");
	sprintf(codename.name, "%s", "中国共产党中央委员会和地方各级组织负责人");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5368");
	sprintf(codename.name, "%s", "国家机关及其工作机构负责人");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5369");
	sprintf(codename.name, "%s", "民主党派和社会团体及其机构负责人");
	m_JobList.push_back(codename);
	
	sprintf(codename.code, "%s", "5370");
	sprintf(codename.name, "%s", "事业单位负责人");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5371");
	sprintf(codename.name, "%s", "企业负责人");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5372");
	sprintf(codename.name, "%s", "科学研究人员");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5373");
	sprintf(codename.name, "%s", "工程技术人员");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5374");
	sprintf(codename.name, "%s", "农业技术人员");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5375");
	sprintf(codename.name, "%s", "飞机和船舶技术人员");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5376");
	sprintf(codename.name, "%s", "飞机和船舶技术人员");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5377");
	sprintf(codename.name, "%s", "经济业务人员");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5378");
	sprintf(codename.name, "%s", "金融业务人员");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5379");
	sprintf(codename.name, "%s", "法律专业人员");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5380");
	sprintf(codename.name, "%s", "教学人员");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5381");
	sprintf(codename.name, "%s", "文学艺术工作人员");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5382");
	sprintf(codename.name, "%s", "体育工作人员");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5383");
	sprintf(codename.name, "%s", "新闻出版、文化工作人员");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5384");
	sprintf(codename.name, "%s", "宗教职业人员");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5385");
	sprintf(codename.name, "%s", "其他专业技术人员");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5386");
	sprintf(codename.name, "%s", "行政办公人员");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5387");
	sprintf(codename.name, "%s", "安全保卫和消防人员");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5388");
	sprintf(codename.name, "%s", "邮电和电信业务人员");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5389");
	sprintf(codename.name, "%s", "其他办事人员和有关人员");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5390");
	sprintf(codename.name, "%s", "购销人员");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5391");
	sprintf(codename.name, "%s", "仓储人员");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5392");
	sprintf(codename.name, "%s", "餐饮服务人员");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5393");
	sprintf(codename.name, "%s", "饭店、旅游及健身娱乐场所服务人员");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5394");
	sprintf(codename.name, "%s", "运输服务人员");
	m_JobList.push_back(codename);
	
	sprintf(codename.code, "%s", "5395");
	sprintf(codename.name, "%s", "医疗卫生辅助服务人员");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5396");
	sprintf(codename.name, "%s", "社会服务和居民生活服务人员");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5397");
	sprintf(codename.name, "%s", "其他商业、服务业人员");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5398");
	sprintf(codename.name, "%s", "种植业生产人员");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5399");
	sprintf(codename.name, "%s", "林业生产和野生植物保护人员");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5400");
	sprintf(codename.name, "%s", "畜牧业生产人员");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5401");
	sprintf(codename.name, "%s", "渔业业生产人员");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5402");
	sprintf(codename.name, "%s", "水利设施管理养护人员人员");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5403");
	sprintf(codename.name, "%s", "水利设施管理养护人员人员");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5404");
	sprintf(codename.name, "%s", "勘测及矿物开采人员");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5405");
	sprintf(codename.name, "%s", "金属冶炼、扎制人员");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5406");
	sprintf(codename.name, "%s", "化工产品生产人员");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5407");
	sprintf(codename.name, "%s", "机械制造加工人员");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5408");
	sprintf(codename.name, "%s", "机电产品装配人员");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5409");
	sprintf(codename.name, "%s", "机械设备修理人员");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5410");
	sprintf(codename.name, "%s", "电力设备安装、运行、检修及供电人员");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5411");
	sprintf(codename.name, "%s", "电子元器件与设备制造、装配、调试及维修人员");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5412");
	sprintf(codename.name, "%s", "橡胶和塑料制品生产人员");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5413");
	sprintf(codename.name, "%s", "橡胶和塑料制品生产人员");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5414");
	sprintf(codename.name, "%s", "剪裁、缝纫和皮革、毛皮制品加工制作人员");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5415");
	sprintf(codename.name, "%s", "剪裁、缝纫和皮革、毛皮制品加工制作人员");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5416");
	sprintf(codename.name, "%s", "烟草及其制品加工人员");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5417");
	sprintf(codename.name, "%s", "药品生产人员");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5418");
	sprintf(codename.name, "%s", "木材加工，木制品制作及制浆，纸制品生产加工人员");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5419");
	sprintf(codename.name, "%s", "建筑材料生产加工人员");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5420");
	sprintf(codename.name, "%s", "玻璃、陶瓷、搪瓷及其制品生产加工人员");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5421");
	sprintf(codename.name, "%s", "广播影视制品制作、播放及文物保护作业人员");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5422");
	sprintf(codename.name, "%s", "印刷人员");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5423");
	sprintf(codename.name, "%s", "工艺、美术品制作人员");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5424");
	sprintf(codename.name, "%s", "文化教育、体育用品制作人员");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5425");
	sprintf(codename.name, "%s", "工程施工人员");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5426");
	sprintf(codename.name, "%s", "运输设备操作人员及有关人员");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5427");
	sprintf(codename.name, "%s", "环境监测与废物处理人员");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5428");
	sprintf(codename.name, "%s", "检验、计量人员");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5429");
	sprintf(codename.name, "%s", "其他生产、运输设备操作人员及有关人员");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5430");
	sprintf(codename.name, "%s", "军人");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5431");
	sprintf(codename.name, "%s", "不便分类的其他从业人员");
	m_JobList.push_back(codename);


	//单位编号列表初始化
	sprintf(codename.code, "%s", "5241");
	sprintf(codename.name, "%s", "政府相关");
	m_UnitIdList.push_back(codename);

	sprintf(codename.code, "%s", "5242");
	sprintf(codename.name, "%s", "教育相关");
	m_UnitIdList.push_back(codename);

	sprintf(codename.code, "%s", "5243");
	sprintf(codename.name, "%s", "工业相关");
	m_UnitIdList.push_back(codename);

	sprintf(codename.code, "%s", "5244");
	sprintf(codename.name, "%s", "农业相关");
	m_UnitIdList.push_back(codename);

	sprintf(codename.code, "%s", "5245");
	sprintf(codename.name, "%s", "个体相关");
	m_UnitIdList.push_back(codename);

	sprintf(codename.code, "%s", "5460");
	sprintf(codename.name, "%s", "学生");
	m_UnitIdList.push_back(codename);

	sprintf(codename.code, "%s", "5461");
	sprintf(codename.name, "%s", "退休人员");
	m_UnitIdList.push_back(codename);

	sprintf(codename.code, "%s", "5462");
	sprintf(codename.name, "%s", "未就业人员");
	m_UnitIdList.push_back(codename);

	sprintf(codename.code, "%s", "5246");
	sprintf(codename.name, "%s", "其他");
	m_UnitIdList.push_back(codename);

	//服务方式数据初始化
	m_strServiceMode.push_back("5143");//集中定点
	m_strServiceMode.push_back("5144");//综合包户
	m_strServiceMode.push_back("5145");//预约上门
	m_strServiceMode.push_back("5146");//其他

	//志愿者特长数据初始化
	m_strZyzSpecialty.push_back("5148");//医护急救
	m_strZyzSpecialty.push_back("5562");//应急救援
	m_strZyzSpecialty.push_back("5149");//体育竞技
	m_strZyzSpecialty.push_back("5150");//驾驶运输
	m_strZyzSpecialty.push_back("5151");//法律服务
	m_strZyzSpecialty.push_back("5152");//信息技术
	m_strZyzSpecialty.push_back("5153");//经营管理
	m_strZyzSpecialty.push_back("5154");//公共关系
	m_strZyzSpecialty.push_back("5155");//教育培训
	m_strZyzSpecialty.push_back("5156");//电器维修
	m_strZyzSpecialty.push_back("5157");//安全保卫
	m_strZyzSpecialty.push_back("5158");//财会金融
	m_strZyzSpecialty.push_back("5159");//客户接待
	m_strZyzSpecialty.push_back("5160");//新闻写作
	m_strZyzSpecialty.push_back("5161");//设计创意
	m_strZyzSpecialty.push_back("5162");//物业养护
	m_strZyzSpecialty.push_back("5163");//摄像摄影
	m_strZyzSpecialty.push_back("5164");//文化艺术
	m_strZyzSpecialty.push_back("5165");//其他

	//服务对象数据初始化
	m_strServiceTarget.push_back("5188");//弱势群体帮助
	m_strServiceTarget.push_back("5189");//问题青少年帮教
	m_strServiceTarget.push_back("5190");//精神病康复者
	m_strServiceTarget.push_back("5191");//弱智人士
	m_strServiceTarget.push_back("5192");//肢体伤残人士
	m_strServiceTarget.push_back("5193");//弱能人士
	m_strServiceTarget.push_back("5194");//弱能人士
	m_strServiceTarget.push_back("5195");//末期病患者
	m_strServiceTarget.push_back("5196");//单亲家庭
	m_strServiceTarget.push_back("5197");//市民大众
	m_strServiceTarget.push_back("5198");//留守儿童
	m_strServiceTarget.push_back("5199");//孤寡老人
	m_strServiceTarget.push_back("5200");//其他

	//可服务时间数据初始化
	m_strCanServiceTime.push_back("5202");//星期一上午（7-12）
	m_strCanServiceTime.push_back("5203");//星期一下午（12-19）
	m_strCanServiceTime.push_back("5204");//星期一晚上（19-21）
	m_strCanServiceTime.push_back("5205");//星期二上午（7-12）
	m_strCanServiceTime.push_back("5206");//星期二下午（12-19）
	m_strCanServiceTime.push_back("5207");//星期二晚上（19-21）
	m_strCanServiceTime.push_back("5208");//星期三上午（7-12）
	m_strCanServiceTime.push_back("5209");//星期三下午（12-19）
	m_strCanServiceTime.push_back("5210");//星期三晚上（19-21）
	m_strCanServiceTime.push_back("5211");//星期四上午（7-12）
	m_strCanServiceTime.push_back("5212");//星期四下午（12-19）
	m_strCanServiceTime.push_back("5213");//星期四晚上（19-21）
	m_strCanServiceTime.push_back("5214");//星期五上午（7-12）
	m_strCanServiceTime.push_back("5215");//星期五下午（12-19）
	m_strCanServiceTime.push_back("5216");//星期五晚上（19-21）
	m_strCanServiceTime.push_back("5217");//星期六上午（7-12）
	m_strCanServiceTime.push_back("5218");//星期六下午（12-19）
	m_strCanServiceTime.push_back("5219");//星期六晚上（19-21）
	m_strCanServiceTime.push_back("5220");//星期日上午（7-12）
	m_strCanServiceTime.push_back("5221");//星期日下午（12-19）
	m_strCanServiceTime.push_back("5222");//星期日晚上（19-21）
}

void CFormData::SetFieldValue(const char* key, std::string value)
{
	m_Fields[key] = value;
}

void CFormData::BuildPostString()
{
	m_strPostParam = "";
	stdext::hash_map<const char*,std::string>::iterator begin = m_Fields.begin(), end = m_Fields.end(), it;
	for(it = begin; it != end ; it++)
	{
		if( it != begin )
		{
			m_strPostParam.append("&");
		}
		m_strPostParam.append(it->first);
		m_strPostParam.append("=");
		m_strPostParam.append(it->second);
	}
	TRACE(">>>>post_str=%s", m_strPostParam.c_str());
}

const char* CFormData::GetCodeByName(std::vector<CODE_NAME>& list, const char* name)
{
	size_t size = list.size();
	for(size_t i=0; i<size; i++)
	{
		if(strcmp(list[i].name, name) == 0)
		{
			return list[i].code;
		}
	}
	return "";
}

const char* CFormData::GetRandomValue(std::vector<const char*>& list)
{
	int rand = getRandomNumber(0, list.size());
	return list[rand];
}

void CFormData::BuildQueryString(const char* idcard)
{
	m_strQueryParam = "zyzCnName=&zyzSex=0&zyzRegisterBeginDate=&zyzRegisterEndDate=&zyzType=0&zyzNumber=&auditState=5009&zyzServiceTimeStart=0.0&zyzServiceTimeEnd=0.0&zyzPapersNumber=";
	m_strQueryParam.append(idcard);
	TRACE(">>>>query_str=%s", m_strQueryParam.c_str());
}
