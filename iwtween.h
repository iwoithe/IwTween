#pragma once

#include <cmath>

namespace iw
{
	template<typename T>
	class Tween
	{
	public:
		Tween() = default;

		Tween(T start, T end)
		{
			m_start = start;
			m_end = end;
		}

		typedef T(*InterpFunc)(T, T, float);

		T at(float alpha, Tween<T>::InterpFunc interpFunc = linearInterp)
		{
			return interpFunc(m_start, m_end, alpha);
		}

		T getStart() const { return m_start; }
		void setStart(T start) { m_start = start; }
		T getEnd() const { return m_end; }
		void setEnd(T end) { m_end = end; }

		float getAlpha() const { return m_alpha; }

		static T linearInterp(T start, T end, float alpha)
		{
			return (end - start) * alpha + start;
		}

		static T easeInCubicInterp(T start, T end, float alpha)
		{
			return (end - start) * alpha * alpha * alpha + start;
		}

		static T easeInOutExpoInterp(T start, T end, float alpha)
		{
			float a = alpha == 0 ? 0 : alpha == 1 ? 1 : alpha < 0.5 ? std::pow(2, 20 * alpha - 10) / 2 : (2 - std::pow(2, -20 * alpha + 10)) / 2;
			return (end - start) * a + start;
		}

		static T easeOutQuartInterp(T start, T end, float alpha)
		{
			float a = 1 - std::pow(1 - alpha, 4);
			return (end - start) * a + start;
		}
	private:
		T m_start;
		T m_end;
		float m_alpha;
	};
}
