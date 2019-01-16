#include<iostream>
#include<set>
#include<string>

class Message;
class Folders
{
	friend Message;
	friend void swap(Folders &lhs, Folders &rhs);
	Folders(const Folders &f);
	void add_to_Message(const Folders &f);
	void remove_from_Message();
	~Folders();
private:
	void addMsg(Message& m);
	void remMsg(Message& m);
	std::set<Message*> messages;
};
void Folders::addMsg(Message& m)
{
	messages.insert(&m);
}

void Folders::remMsg(Message& m)
{
	messages.erase(&m);
}

void swap(Folders &lhs, Folders &rhs)
{
	using std::swap;
	lhs.remove_from_Message();
	rhs.remove_from_Message();

	swap(lhs.messages, rhs.messages);

	lhs.add_to_Message(lhs);
	rhs.add_to_Message(rhs);
}

void Folders::add_to_Message(const Folders &f)
{
	for (auto m : f.messages)
		m->save(f);
}

Folders::Folders(const Folders &f) : messages(f.messages)
{
	add_to_Message(f);
}

void Folders::remove_from_Message()
{
	for (auto m : messages)
		m->remove(*this);
}

Folders::~Folders()
{
	remove_from_Message();
}

Folders &Folders::operator=(const Folders &rhs)
{
	remove_from_Message();
	messages = rhs.messages;
	add_to_Message(rhs);
	return *this;
}

class Message {
	friend class folder;
public:
	explicit Message(const std::string &str = "") : contents(str) {};
	Message(const Message&);
	Message& operator=(const Message&);
	void save(Folders&); //save the Message to a specific folder
	void remove(Folders&); //remove the Message from a Folder
	friend void swap(Message &lhs, Message &rhs);
private:
	std::string contents; //the actual message
	std::set<Folders*> folders; //Folders containing message
	void add_to_folders(const Message&); //add to the folders
	void remove_from_Folders();//remove the pointers
	~Message();
};


void Message::save(Folders& f)
{
	folders.insert(&f); //add this folder to the Message
	f.addMsg(*this);     //add the Message to the folder
}

void Message::remove(Folders& f)
{
	folders.erase(&f);  //erase the folder from the folderlist
	f.remMsg(*this);     //delete the message from your folder list
}

void Message::add_to_folders(const Message &m) 
{
	for (auto f : m.folders)
		f->addMsg(*this);
}

Message::Message(const Message& m) : contents(m.contents), folders(m.folders)
{
	add_to_folders(m);
}

void Message::remove_from_Folders()
{
	for (auto f : folders)
		f->remMsg(*this);
}

Message::~Message()
{
	remove_from_Folders();
}

Message& Message::operator=(const Message& m) 
{
	remove_from_Folders();
	contents = m.contents;
	folders = m.folders;
	add_to_folders(m);
	return *this;
}

Message::Message(const Message& m)
{
	*this = m;
}

void  swap(Message & lhs, Message &rhs)
{
	//remove from the original folder, prepare
	for (auto f : lhs.folders)
		f->remMsg(&lhs);
	for (auto f : rhs.folders)
		f.remMsg(&rhs);
	//swap the folders and content
	swap(lhs.folders, rhs.folders);
	swap(lhs.contents, rhs.contents);
	//add to the new folder
	for (auto f : lhs.folders)
		f.addMsg(&lhs);
	for (auto f : rhs.folders)
		f.addMsg(&rhs);
}