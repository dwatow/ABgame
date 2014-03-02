class Topic
{
	bool m_isRepet;
	char m_letterTopic;
public:
	Topic():m_letterTopic(0), m_isRepet(false){};
	Topic(char letter):m_letterTopic(letter), m_isRepet(false){}

	void Repet(){ m_isRepet = true; }
	bool IsRepet(){ return m_isRepet; }

	void setTopic(char _T){ m_letterTopic = _T; }
	char getTopic(){ return m_letterTopic; }

	void clear(){ m_letterTopic = 0; m_isRepet = false; }

};