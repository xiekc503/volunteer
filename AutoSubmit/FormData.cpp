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
	m_Fields["zyzPapersType"] = "1717";//�ڵؾ������֤
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
	m_Fields["serviceProvinceName"] = "������";
	m_Fields["serviceProvince"] = "588702";
	m_Fields["serviceCityName"] = "������";
	m_Fields["serviceCity"] = "785874";
	m_Fields["serviceCountyName"] = "������";
	m_Fields["serviceCounty"] = "591677";
	m_Fields["serviceStreetName"] = "�㶴�ֵ�";
	m_Fields["serviceStreet"] = "591678";
	m_Fields["serviceCommuntityName"] = "�����������ί��";
	m_Fields["serviceCommuntity"] = "591687";
	m_Fields["serviceDetail"] = "";
	m_Fields["provinceName"] = "������";
	m_Fields["province"] = "588702";
	m_Fields["cityName"] = "������";
	m_Fields["city"] = "785874";
	m_Fields["countyName"] = "������";
	m_Fields["county"] = "591677";
	m_Fields["streetName"] = "�㶴�ֵ�";
	m_Fields["street"] = "591678";
	m_Fields["communtityName"] = "�����������ί��";
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
	//��ʼ���Ա��б�
	sprintf(codename.code, "%s", "119");
	sprintf(codename.name, "%s", "��");
	m_SexList.push_back(codename);

	sprintf(codename.code, "%s", "120");
	sprintf(codename.name, "%s", "Ů");
	m_SexList.push_back(codename);

	//��ʼ��ְҵ�����б�
	sprintf(codename.code, "%s", "5367");
	sprintf(codename.name, "%s", "�й�����������ίԱ��͵ط�������֯������");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5368");
	sprintf(codename.name, "%s", "���һ��ؼ��乤������������");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5369");
	sprintf(codename.name, "%s", "�������ɺ�������弰�����������");
	m_JobList.push_back(codename);
	
	sprintf(codename.code, "%s", "5370");
	sprintf(codename.name, "%s", "��ҵ��λ������");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5371");
	sprintf(codename.name, "%s", "��ҵ������");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5372");
	sprintf(codename.name, "%s", "��ѧ�о���Ա");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5373");
	sprintf(codename.name, "%s", "���̼�����Ա");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5374");
	sprintf(codename.name, "%s", "ũҵ������Ա");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5375");
	sprintf(codename.name, "%s", "�ɻ��ʹ���������Ա");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5376");
	sprintf(codename.name, "%s", "�ɻ��ʹ���������Ա");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5377");
	sprintf(codename.name, "%s", "����ҵ����Ա");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5378");
	sprintf(codename.name, "%s", "����ҵ����Ա");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5379");
	sprintf(codename.name, "%s", "����רҵ��Ա");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5380");
	sprintf(codename.name, "%s", "��ѧ��Ա");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5381");
	sprintf(codename.name, "%s", "��ѧ����������Ա");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5382");
	sprintf(codename.name, "%s", "����������Ա");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5383");
	sprintf(codename.name, "%s", "���ų��桢�Ļ�������Ա");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5384");
	sprintf(codename.name, "%s", "�ڽ�ְҵ��Ա");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5385");
	sprintf(codename.name, "%s", "����רҵ������Ա");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5386");
	sprintf(codename.name, "%s", "�����칫��Ա");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5387");
	sprintf(codename.name, "%s", "��ȫ������������Ա");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5388");
	sprintf(codename.name, "%s", "�ʵ�͵���ҵ����Ա");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5389");
	sprintf(codename.name, "%s", "����������Ա���й���Ա");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5390");
	sprintf(codename.name, "%s", "������Ա");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5391");
	sprintf(codename.name, "%s", "�ִ���Ա");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5392");
	sprintf(codename.name, "%s", "����������Ա");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5393");
	sprintf(codename.name, "%s", "���ꡢ���μ��������ֳ���������Ա");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5394");
	sprintf(codename.name, "%s", "���������Ա");
	m_JobList.push_back(codename);
	
	sprintf(codename.code, "%s", "5395");
	sprintf(codename.name, "%s", "ҽ����������������Ա");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5396");
	sprintf(codename.name, "%s", "������;������������Ա");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5397");
	sprintf(codename.name, "%s", "������ҵ������ҵ��Ա");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5398");
	sprintf(codename.name, "%s", "��ֲҵ������Ա");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5399");
	sprintf(codename.name, "%s", "��ҵ������Ұ��ֲ�ﱣ����Ա");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5400");
	sprintf(codename.name, "%s", "����ҵ������Ա");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5401");
	sprintf(codename.name, "%s", "��ҵҵ������Ա");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5402");
	sprintf(codename.name, "%s", "ˮ����ʩ����������Ա��Ա");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5403");
	sprintf(codename.name, "%s", "ˮ����ʩ����������Ա��Ա");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5404");
	sprintf(codename.name, "%s", "���⼰���￪����Ա");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5405");
	sprintf(codename.name, "%s", "����ұ����������Ա");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5406");
	sprintf(codename.name, "%s", "������Ʒ������Ա");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5407");
	sprintf(codename.name, "%s", "��е����ӹ���Ա");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5408");
	sprintf(codename.name, "%s", "�����Ʒװ����Ա");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5409");
	sprintf(codename.name, "%s", "��е�豸������Ա");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5410");
	sprintf(codename.name, "%s", "�����豸��װ�����С����޼�������Ա");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5411");
	sprintf(codename.name, "%s", "����Ԫ�������豸���졢װ�䡢���Լ�ά����Ա");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5412");
	sprintf(codename.name, "%s", "�𽺺�������Ʒ������Ա");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5413");
	sprintf(codename.name, "%s", "�𽺺�������Ʒ������Ա");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5414");
	sprintf(codename.name, "%s", "���á����Һ�Ƥ�ëƤ��Ʒ�ӹ�������Ա");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5415");
	sprintf(codename.name, "%s", "���á����Һ�Ƥ�ëƤ��Ʒ�ӹ�������Ա");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5416");
	sprintf(codename.name, "%s", "�̲ݼ�����Ʒ�ӹ���Ա");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5417");
	sprintf(codename.name, "%s", "ҩƷ������Ա");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5418");
	sprintf(codename.name, "%s", "ľ�ļӹ���ľ��Ʒ�������ƽ���ֽ��Ʒ�����ӹ���Ա");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5419");
	sprintf(codename.name, "%s", "�������������ӹ���Ա");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5420");
	sprintf(codename.name, "%s", "�������մɡ��´ɼ�����Ʒ�����ӹ���Ա");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5421");
	sprintf(codename.name, "%s", "�㲥Ӱ����Ʒ���������ż����ﱣ����ҵ��Ա");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5422");
	sprintf(codename.name, "%s", "ӡˢ��Ա");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5423");
	sprintf(codename.name, "%s", "���ա�����Ʒ������Ա");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5424");
	sprintf(codename.name, "%s", "�Ļ�������������Ʒ������Ա");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5425");
	sprintf(codename.name, "%s", "����ʩ����Ա");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5426");
	sprintf(codename.name, "%s", "�����豸������Ա���й���Ա");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5427");
	sprintf(codename.name, "%s", "�����������ﴦ����Ա");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5428");
	sprintf(codename.name, "%s", "���顢������Ա");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5429");
	sprintf(codename.name, "%s", "���������������豸������Ա���й���Ա");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5430");
	sprintf(codename.name, "%s", "����");
	m_JobList.push_back(codename);

	sprintf(codename.code, "%s", "5431");
	sprintf(codename.name, "%s", "��������������ҵ��Ա");
	m_JobList.push_back(codename);


	//��λ����б��ʼ��
	sprintf(codename.code, "%s", "5241");
	sprintf(codename.name, "%s", "�������");
	m_UnitIdList.push_back(codename);

	sprintf(codename.code, "%s", "5242");
	sprintf(codename.name, "%s", "�������");
	m_UnitIdList.push_back(codename);

	sprintf(codename.code, "%s", "5243");
	sprintf(codename.name, "%s", "��ҵ���");
	m_UnitIdList.push_back(codename);

	sprintf(codename.code, "%s", "5244");
	sprintf(codename.name, "%s", "ũҵ���");
	m_UnitIdList.push_back(codename);

	sprintf(codename.code, "%s", "5245");
	sprintf(codename.name, "%s", "�������");
	m_UnitIdList.push_back(codename);

	sprintf(codename.code, "%s", "5460");
	sprintf(codename.name, "%s", "ѧ��");
	m_UnitIdList.push_back(codename);

	sprintf(codename.code, "%s", "5461");
	sprintf(codename.name, "%s", "������Ա");
	m_UnitIdList.push_back(codename);

	sprintf(codename.code, "%s", "5462");
	sprintf(codename.name, "%s", "δ��ҵ��Ա");
	m_UnitIdList.push_back(codename);

	sprintf(codename.code, "%s", "5246");
	sprintf(codename.name, "%s", "����");
	m_UnitIdList.push_back(codename);

	//����ʽ���ݳ�ʼ��
	m_strServiceMode.push_back("5143");//���ж���
	m_strServiceMode.push_back("5144");//�ۺϰ���
	m_strServiceMode.push_back("5145");//ԤԼ����
	m_strServiceMode.push_back("5146");//����

	//־Ը���س����ݳ�ʼ��
	m_strZyzSpecialty.push_back("5148");//ҽ������
	m_strZyzSpecialty.push_back("5562");//Ӧ����Ԯ
	m_strZyzSpecialty.push_back("5149");//��������
	m_strZyzSpecialty.push_back("5150");//��ʻ����
	m_strZyzSpecialty.push_back("5151");//���ɷ���
	m_strZyzSpecialty.push_back("5152");//��Ϣ����
	m_strZyzSpecialty.push_back("5153");//��Ӫ����
	m_strZyzSpecialty.push_back("5154");//������ϵ
	m_strZyzSpecialty.push_back("5155");//������ѵ
	m_strZyzSpecialty.push_back("5156");//����ά��
	m_strZyzSpecialty.push_back("5157");//��ȫ����
	m_strZyzSpecialty.push_back("5158");//�ƻ����
	m_strZyzSpecialty.push_back("5159");//�ͻ��Ӵ�
	m_strZyzSpecialty.push_back("5160");//����д��
	m_strZyzSpecialty.push_back("5161");//��ƴ���
	m_strZyzSpecialty.push_back("5162");//��ҵ����
	m_strZyzSpecialty.push_back("5163");//������Ӱ
	m_strZyzSpecialty.push_back("5164");//�Ļ�����
	m_strZyzSpecialty.push_back("5165");//����

	//����������ݳ�ʼ��
	m_strServiceTarget.push_back("5188");//����Ⱥ�����
	m_strServiceTarget.push_back("5189");//������������
	m_strServiceTarget.push_back("5190");//���񲡿�����
	m_strServiceTarget.push_back("5191");//������ʿ
	m_strServiceTarget.push_back("5192");//֫���˲���ʿ
	m_strServiceTarget.push_back("5193");//������ʿ
	m_strServiceTarget.push_back("5194");//������ʿ
	m_strServiceTarget.push_back("5195");//ĩ�ڲ�����
	m_strServiceTarget.push_back("5196");//���׼�ͥ
	m_strServiceTarget.push_back("5197");//�������
	m_strServiceTarget.push_back("5198");//���ض�ͯ
	m_strServiceTarget.push_back("5199");//�¹�����
	m_strServiceTarget.push_back("5200");//����

	//�ɷ���ʱ�����ݳ�ʼ��
	m_strCanServiceTime.push_back("5202");//����һ���磨7-12��
	m_strCanServiceTime.push_back("5203");//����һ���磨12-19��
	m_strCanServiceTime.push_back("5204");//����һ���ϣ�19-21��
	m_strCanServiceTime.push_back("5205");//���ڶ����磨7-12��
	m_strCanServiceTime.push_back("5206");//���ڶ����磨12-19��
	m_strCanServiceTime.push_back("5207");//���ڶ����ϣ�19-21��
	m_strCanServiceTime.push_back("5208");//���������磨7-12��
	m_strCanServiceTime.push_back("5209");//���������磨12-19��
	m_strCanServiceTime.push_back("5210");//���������ϣ�19-21��
	m_strCanServiceTime.push_back("5211");//���������磨7-12��
	m_strCanServiceTime.push_back("5212");//���������磨12-19��
	m_strCanServiceTime.push_back("5213");//���������ϣ�19-21��
	m_strCanServiceTime.push_back("5214");//���������磨7-12��
	m_strCanServiceTime.push_back("5215");//���������磨12-19��
	m_strCanServiceTime.push_back("5216");//���������ϣ�19-21��
	m_strCanServiceTime.push_back("5217");//���������磨7-12��
	m_strCanServiceTime.push_back("5218");//���������磨12-19��
	m_strCanServiceTime.push_back("5219");//���������ϣ�19-21��
	m_strCanServiceTime.push_back("5220");//���������磨7-12��
	m_strCanServiceTime.push_back("5221");//���������磨12-19��
	m_strCanServiceTime.push_back("5222");//���������ϣ�19-21��
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
