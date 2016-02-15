#ifndef COMMAND_TABLE_H
#define COMMAND_TABLE_H
#include "../icommand.h"
#include <QString>
#include <QStringList>

class CommandTable : public ICommand {
	public:
		CommandTable();
		virtual bool isMultiLine();
		virtual ICommand *create();
		virtual QString name();
		virtual void setParams(QStringList list);
		virtual bool check();
		virtual bool check(QString &strResult);
		virtual QString code();
		virtual void appendCode(QString);
		virtual void run(Frame *pFrame, DrawObjectsCollection *pDrawObjectsCollection);
	private:
		void drawGrid(Frame *pFrame, int nX, int nY, QVector<int> &vColumnsWidth, int nRows, int nRowHeight, int nWidth, int nColor);
		QString m_strName;
		QStringList m_listParams;
		QStringList m_listCode;
};

#endif // COMMAND_TABLE_H
