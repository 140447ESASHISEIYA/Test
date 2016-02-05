#include "Tree.h"
#include "Line.h"


HRESULT Tree::Render()
{

	LineRender(D3DXVECTOR3(0, -2, 0), D3DXVECTOR3(0, 1, 0), 10);

	return S_OK;
}


void Tree::LineRender(D3DXVECTOR3 start, D3DXVECTOR3 dir, int deep)
{
	Line line;
	line.Draw(start, start + dir);

	float d = 0.8;
	float angle = 30;	//変更

	D3DXMATRIX right, left;
	D3DXVECTOR3 vec;
	D3DXVECTOR3 vR, vL;

	//start = start + dir;

	vec = dir;
	D3DXMatrixRotationZ(&right, D3DXToRadian(-angle));
	D3DXVec3TransformCoord(&vec, &dir, &right);
	vec *= d;
	line.Draw(start + dir, start + dir + vec);
	vR = vec;

	vec = dir;
	D3DXMatrixRotationZ(&left, D3DXToRadian(angle));
	D3DXVec3TransformCoord(&vec, &dir, &left);
	vec *= d;
	line.Draw(start + dir, start + dir + vec);
	vL = vec;

	if (deep >= 1)
	{
		vec = vR;
		D3DXMatrixRotationZ(&right, D3DXToRadian(-angle));
		D3DXVec3TransformCoord(&vec, &vec, &right);
		vec *= d;
		LineRender(start + dir + vR, vec, deep - 1);

		vec = vL;
		D3DXMatrixRotationZ(&left, D3DXToRadian(angle));
		D3DXVec3TransformCoord(&vec, &vec, &left);
		vec *= d;
		LineRender(start + dir + vL, vec, deep - 1);
	}

	//start = start + vec;
	//Hello
	//メッセージ

}