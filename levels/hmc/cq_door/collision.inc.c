const Collision cq_door_collision[] = {
	COL_INIT(),
	COL_VERTEX_INIT(16),
	COL_VERTEX(-293, 0, 110),
	COL_VERTEX(-293, 0, -110),
	COL_VERTEX(293, 0, -110),
	COL_VERTEX(293, 0, 110),
	COL_VERTEX(-293, 533, 110),
	COL_VERTEX(293, 533, 110),
	COL_VERTEX(293, 533, -110),
	COL_VERTEX(-293, 533, -110),
	COL_VERTEX(196, 436, -110),
	COL_VERTEX(196, 96, -110),
	COL_VERTEX(196, 96, -28),
	COL_VERTEX(196, 436, -28),
	COL_VERTEX(-196, 96, -110),
	COL_VERTEX(-196, 436, -110),
	COL_VERTEX(-196, 96, -28),
	COL_VERTEX(-196, 436, -28),
	COL_TRI_INIT(SURFACE_DEFAULT, 28),
	COL_TRI(0, 1, 2),
	COL_TRI(0, 2, 3),
	COL_TRI(4, 5, 6),
	COL_TRI(4, 6, 7),
	COL_TRI(0, 3, 5),
	COL_TRI(0, 5, 4),
	COL_TRI(1, 0, 4),
	COL_TRI(1, 4, 7),
	COL_TRI(3, 2, 6),
	COL_TRI(3, 6, 5),
	COL_TRI(8, 9, 10),
	COL_TRI(8, 10, 11),
	COL_TRI(12, 9, 2),
	COL_TRI(12, 2, 1),
	COL_TRI(8, 13, 7),
	COL_TRI(8, 7, 6),
	COL_TRI(13, 12, 1),
	COL_TRI(13, 1, 7),
	COL_TRI(9, 8, 6),
	COL_TRI(9, 6, 2),
	COL_TRI(10, 14, 15),
	COL_TRI(10, 15, 11),
	COL_TRI(13, 8, 11),
	COL_TRI(13, 11, 15),
	COL_TRI(12, 13, 15),
	COL_TRI(12, 15, 14),
	COL_TRI(9, 12, 14),
	COL_TRI(9, 14, 10),
	COL_TRI_STOP(),
	COL_END()
};
