

public class QuaternionData {
	protected double x, y, z, w;
	protected double roll, pitch, yaw;

	protected boolean settingQuaternionData() {
		x = 0;
		y = 0;
		z = 0;
		w = 1.0;
		roll = 0;
		pitch = 0;
		yaw = 0;
		return true;
	}
}
