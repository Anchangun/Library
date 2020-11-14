public class EulerToQuaternion extends QuaternionData {


	private double cos_roll;
	private double sin_roll;

	private double cos_pitch;
	private double sin_pitch;
	private double cos_yaw;
	private double sin_yaw;
	private double origin_w_magnification;

	public EulerToQuaternion() {
		settingQuaternionData();
	}

	public void eulerToQuaternion(double roll, double pitch, double yaw) {
		cos_roll = Math.cos(roll);
		sin_roll = Math.sin(roll);
		cos_pitch = Math.cos(pitch);
		sin_pitch = Math.sin(pitch);
		cos_yaw = Math.cos(yaw);
		sin_yaw = Math.sin(yaw);
		w = Math.sqrt(1.0 + cos_roll * cos_pitch + cos_roll * cos_yaw - sin_roll * sin_pitch * sin_yaw + cos_pitch * cos_yaw) / 2.0;
		origin_w_magnification = (4.0 * w);
		x = (cos_pitch * sin_yaw + cos_roll * sin_yaw + sin_roll * sin_pitch * cos_yaw) / origin_w_magnification;
		y = (sin_roll * cos_pitch + sin_roll * cos_yaw + cos_roll * sin_pitch * sin_yaw) / origin_w_magnification;
		z = (-sin_roll * sin_yaw + cos_roll * sin_pitch * cos_yaw + sin_pitch) / origin_w_magnification;

	}
	public double getterEulerX() {
		return x;
	}
	public double getterEulerY() {
		return y;
	}
	public double getterEulerZ() {
		return z;
	}
	public double getterEulerW() {
		return w;
	}
}
