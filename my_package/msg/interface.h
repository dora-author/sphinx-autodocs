

// socket interface
namespace morai::msg {	
	// Socket interface class
	class PUBLIC_EXPORT IMsg
	{		
	public:
		virtual ~IMsg() {};
		virtual bool Serialize(char* buffer, int buff_size, int index);
        virtual bool Deserialize(char* data, int data_size, int index);
	};
}